///
/// \file json_utils.hpp
///
/// \brief Defines the utility routines used internally by JSON
///
/// Created on: Jun 23, 2014
/// Author: rdumitriu at gmail.com
///
#ifndef GERYON_JSON_UTILS_HPP_
#define GERYON_JSON_UTILS_HPP_

#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <memory>

namespace ll1gen { namespace json {

void encodeJsonString(const std::string & orig, std::string & final) {
    char * c = const_cast<char *>(orig.c_str());
    while(*c) {
        switch(*c) {
            case '\"':
                final.append("\\\"");
                break;
            case '\\':
                final.append("\\\\");
                break;
            case '/':
                final.append("\\/");
                break;
            case '\b':
                final.append("\\b");
                break;
            case '\n':
                final.append("\\n");
                break;
            case '\f':
                final.append("\\f");
                break;
            case '\r':
                final.append("\\r");
                break;
            case '\t':
                final.append("\\t");
                break;
            default:
                if(0x00 <= *c && *c <= 0x1F) {
                    char buf[8];
                    sprintf(buf,"\\u%04X",*c);
                    final.append(buf);
                } else {
                    final.push_back(*c);
                }
                break;
        }
        ++c;
    }
}

std::string encodeJsonString(const std::string & orig) {
    std::string final;
    encodeJsonString(orig, final);
    return final;
}

char lookUpAndEat(std::istream& stream, const std::string & ends) {
    bool found = false;
    char c = 0;
    do {
        c = stream.get();
        if(stream.bad()) {
            throw std::runtime_error("Encountered premature EOF");
        }
//        std::cout << "Char >" << c << "<" << std::endl;
        if(!isblank(c) && c != '\n' && c != '\r') {
            found = (ends.find(c) != std::string::npos);
            if(!found) {
                std::ostringstream msg;
                msg << "Parse error, found char >>" << c << "<< but was expecting " << ends;
                throw std::runtime_error(msg.str());
            }
        }
    } while( !found );
    return c;
}

std::string lookUp(std::istream& stream, const std::string & ends) {
    bool found = false;
    int state = 0;
    std::string ret;
    char c = 0;
    char unicodeBuff[5];
    int unicodeLen = 0;

    do {
        c = stream.get();
        if(stream.bad()) {
            throw std::runtime_error("Encountered premature EOF");
        }
//        std::cout << "Char >" << c << "< State :" << state << std::endl;

        switch(state) {
            case 1:
                switch(c) {
                    case 'b':
                        state = 0;
                        ret.push_back('\b');
                        break;
                    case 'n':
                        state = 0;
                        ret.push_back('\n');
                        break;
                    case 'f':
                        state = 0;
                        ret.push_back('\f');
                        break;
                    case 'r':
                        state = 0;
                        ret.push_back('\r');
                        break;
                    case 't':
                        state = 0;
                        ret.push_back('\t');
                        break;
                    case 'u':
                        unicodeLen = 0;
                        state = 2;
                        break;
                    default:
                        state = 0;
                        ret.push_back(c);
                        break;
                }
                break;
            case 2: //unicode: next 4 chars are a numeric code
                unicodeBuff[unicodeLen] = c;
                ++unicodeLen;
                if(unicodeLen == 4) {
                    unicodeBuff[4] = 0;
                    int charCode;
                    sscanf(unicodeBuff,"%04X",&charCode);
                    if(0x00 <= charCode && charCode <= 0x1F) {
                        ret.push_back(static_cast<char>(charCode));
                    }
                    state = 0;
                }
                break;
            case 0:
                if(c == '\\') {
                    state = 1;
                } else {
                    found = (ends.find(c) != std::string::npos);
                    if(!found) {
                        ret.push_back(c);
                    }
                }
                break;
        }
    } while( !found );
    return ret;
}


} }

#endif
