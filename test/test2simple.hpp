//
// GENERATED by ll1gen : Do not modify (or on your own risk)
//
#ifndef _LL1GEN_TEST2SIMPLE_HPP_
#define _LL1GEN_TEST2SIMPLE_HPP_

#include "json_utils.hpp"

//ll1gen::include_begin

//ll1gen::include_end

namespace test { 

class Test2Simple {
public:
    //ll1gen::constructor_begin

    //ll1gen::constructor_end
    Test2Simple() {}
    ~Test2Simple() {}

#ifndef LL1GEN_DISABLE_STANDARD_GETTERS
    //ll1gen::getters_begin

    
    std::shared_ptr<std::string>  get_optionalName() const { return _optionalName; }

    void set_optionalName(  std::shared_ptr<std::string>   __val) { _optionalName = __val; }



    bool get_isBool() const { return _isBool; }

    void set_isBool(  bool  __val) { _isBool = __val; }



    std::shared_ptr<bool>  get_isReallyBool() const { return _isReallyBool; }

    void set_isReallyBool(  std::shared_ptr<bool>   __val) { _isReallyBool = __val; }



    int get_number() const { return _number; }

    void set_number(  int  __val) { _number = __val; }


//ll1gen::getters_end
#endif

#ifndef LL1GEN_DISABLE_REFERENCE_GETTERS
    //ll1gen::ref_getters_begin

        std::shared_ptr<std::string>  & optionalName() { return _optionalName; }


    bool & isBool() { return _isBool; }


    std::shared_ptr<bool>  & isReallyBool() { return _isReallyBool; }


    int & number() { return _number; }


//ll1gen::ref_getters_end
#endif

    friend std::ostream& operator<< (std::ostream& __stream, const Test2Simple& __bean);
    friend std::istream& operator>> (std::istream& __stream, Test2Simple& __bean);
private:
    //ll1gen::field_decl_begin

    std::shared_ptr<std::string>  _optionalName;
bool _isBool;
std::shared_ptr<bool>  _isReallyBool;
int _number;
//ll1gen::field_decl_end
};

std::ostream& operator<< (std::ostream& __stream, const Test2Simple& __bean) {
    __stream << "{";
    //ll1gen::field_ostream_begin

        if(__bean._optionalName.get()) {
        __stream << "\"optionalName\":" << "\"" << ll1gen::json::detail::encodeJsonString(*(__bean._optionalName)) << "\"";
    } else {
        __stream << "\"optionalName\": null";
    }

__stream << ",";
    __stream << "\"isBool\":" << (__bean._isBool ? "true" : "false");


__stream << ",";
    if(__bean._isReallyBool.get()) {
        __stream << "\"isReallyBool\":" << (*(__bean._isReallyBool) ? "true" : "false");
    } else {
        __stream << "\"isReallyBool\": null";
    }


__stream << ",";
    __stream << "\"number\":" << __bean._number;


//ll1gen::field_ostream_end
    __stream << "}";
    return __stream;
}

std::istream& operator>> (std::istream& __stream, Test2Simple& __bean) {
    char __startObjectMrk = ll1gen::json::detail::lookUpAndEat(__stream, "{n");
    if(__startObjectMrk == 'n') {
        ll1gen::json::detail::lookUpTokenRemainder(__stream, __startObjectMrk, "null");
        return __stream;
    }
    for(unsigned int __i = 0; __i < 4; ++__i) {
        ll1gen::json::detail::lookUpAndEat(__stream, "\"");
        std::string __propertyName = ll1gen::json::detail::lookUp(__stream, "\"");
        ll1gen::json::detail::lookUpAndEat(__stream, ":");

        //ll1gen::field_istream_begin

            if(__propertyName == "optionalName") {
        __bean._optionalName = std::make_shared<std::string>();
        if(!ll1gen::json::detail::lookUpNull(__stream)) {
            ll1gen::json::detail::parseString(__stream, *(__bean._optionalName));
        } else {
            __bean._optionalName.reset();
        }
    }

else
    if(__propertyName == "isBool") {
        if(!ll1gen::json::detail::parseBool(__stream, __bean._isBool)) {
            throw std::runtime_error("JSON: null is not supported for isBool (bool). Check definition.");
        }
    }

else
    if(__propertyName == "isReallyBool") {
        __bean._isReallyBool = std::make_shared<bool>();
        if(!ll1gen::json::detail::lookUpNull(__stream)) {
            ll1gen::json::detail::parseBool(__stream, *(__bean._isReallyBool));
        } else {
            __bean._isReallyBool.reset();
        }
    }

else
    if(__propertyName == "number") {
        if(!ll1gen::json::detail::lookUpNull(__stream)) {
            __stream >> __bean._number;
        } else {
            throw std::runtime_error("JSON: null not supported for field number. Check definition");
        }
    }

//ll1gen::field_istream_end

        if('}' == ll1gen::json::detail::lookUpAndEat(__stream, "},")) {
            break;
        }
    }
    return __stream;
}

} 

#endif
