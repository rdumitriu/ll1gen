
#include <utility>
#include <iostream>

#include <boost/algorithm/string.hpp>

#include "spec_parser.hpp"

namespace ll1gen {

bool SpecificationParser::parse(std::istream & in) {
    std::string s;
    unsigned int line = 1;
    while(std::getline(in, s)) {
        boost::trim(s);
        if(!processLine(line, s)) {
            return false;
        }
        line++;
    }
    return true;
}

bool SpecificationParser::processLine(int line, const std::string & s) {
    //this line is trimmed, so we need to see how we're called
    if(s.size() == 0) {
        return true;
    }
    if(boost::starts_with(s, "//") || boost::starts_with(s, "#")) {
        return true;
    }

    bool err;
    if(boost::starts_with(s, "namespace ") || boost::starts_with(s, "namespace\t")) {
        err = processNamespace(s);
    } else if(boost::starts_with(s, "class ") || boost::starts_with(s, "class\t")) {
        err = processClassDefinition(s);
    } else {
        err = processFieldDefinition(s);
    }
    if(!err) {
        addError(line);
    }
    return err;
}

bool SpecificationParser::processNamespace(const std::string & s) {
    if(spec.getBeans().size() > 0) {
        lastError = "Namespace should be first, don't mix them";
        return false;
    }
    //namespace = 10 chars
    std::string nms = s.substr(10);
    boost::trim(nms);
    if(!isIdentifier(nms)) {
        lastError = "Namespace >>" + nms + "<< doesn't seem to be an identifier.";
        return false;
    }
    spec.getNamespaces().push_back(nms);
    return true;
}

bool SpecificationParser::processClassDefinition(const std::string & s) {
    //class = 6 chars
    std::string clz = s.substr(6);
    boost::trim(clz);
    if(!isIdentifier(clz)) {
        lastError = "Class >>" + clz + "<< doesn't seem to be an identifier.";
        return false;
    }
    spec.getBeans().push_back(BeanClazzSpecification(clz));
    return true;
}

bool SpecificationParser::processFieldDefinition(const std::string & s) {
    if(spec.getBeans().empty()) {
        lastError = "Field definition without a class specification? Here: >>" + s + "<<";
        return false;
    }
    std::vector<std::string> strs;
    boost::split(strs, s, boost::is_any_of(" \t"));
    if(strs.empty() || strs.size() == 1) {
        lastError = "Invalid field definition >>" + s + "<<";
        return false;
    }
    //first string is the identifier, so:
    std::string ident = strs.at(0);
    if(!isIdentifier(ident)) {
        lastError = "Field >>" + ident + "<< doesn't seem to be an identifier.";
        return false;
    }
    //second: type or flags ?
    unsigned int concatFrom;
    unsigned int flags = 0;
    std::string mod_or_type = strs.at(1);
    if(mod_or_type == "*+" || mod_or_type == "+*" || mod_or_type == "*" || mod_or_type == "+") {
        char * p = const_cast<char *>(mod_or_type.c_str());
        concatFrom = 2;
        while(*p) {
            switch(*p) {
            case '*':
                flags |= F_POINTER;
                break;
            case '+':
                flags |= F_VECTOR;
                break;
            }
            ++p;
        }
    } else { //no flags
        concatFrom = 1;
    }
    std::string thetype;
    for(unsigned int i = concatFrom; i < strs.size(); ++i) {
        thetype += strs.at(i) + " ";
    }
    boost::trim(thetype);
    if(thetype == "") {
        //no type specified?
        lastError = "No type specified? Invalid field definition >>" + s + "<<";
        return false;
    }
    spec.getLastBean().getFields().push_back(FieldSpecification(ident, thetype, flags));
    return true;
}

bool SpecificationParser::isIdentifier(const std::string & s) {
    char * p = const_cast<char *>(s.c_str());
    //what about the first char ?!?
    while(*p) {
        if(('a' > *p || *p > 'z') && ('A' > *p || *p > 'Z') && ('0' > *p || *p > '9') && *p != '_') {
            return false;
        }
        ++p;
    }
    return true;
}

void SpecificationParser::addError(unsigned int line) {
    ErrorLine e;
    e.line = line;
    e.msg = lastError;
    errs.push_back(e);
}

void SpecificationParser::printErrors() {
    for(ErrorLine & el : errs) {
        std::cerr << "ERROR: Line [" << el.line << "] " << el.msg << std::endl;
    }
}

} /*namespace */
