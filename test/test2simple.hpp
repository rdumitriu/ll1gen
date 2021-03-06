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
    Test2Simple(
    		     std::shared_ptr<std::string>   __optionalName

,
     bool  __isBool

,
     std::shared_ptr<bool>   __isReallyBool

,
     int  __number

//ll1gen::constructor_param
              ) :
    		    _optionalName(__optionalName)

,
    _isBool(__isBool)

,
    _isReallyBool(__isReallyBool)

,
    _number(__number)

//ll1gen::constructor_assign
		{}
    //ll1gen::constructor_begin

    //ll1gen::copy_constructor_begin
    Test2Simple(const Test2Simple & __bean) :
    		    _optionalName(__bean._optionalName)

,
    _isBool(__bean._isBool)

,
    _isReallyBool(__bean._isReallyBool)

,
    _number(__bean._number)

//ll1gen::copy_constructor_assign
		{}
    //ll1gen::copy_constructor_end

    Test2Simple() {}
    virtual ~Test2Simple() {}

    //ll1gen::getters_begin

    
    inline
    const std::shared_ptr<std::string>  & getOptionalName() const { return _optionalName; }

    inline
    void setOptionalName(  std::shared_ptr<std::string>   __val) { _optionalName = __val; }



    inline
    const bool & getIsBool() const { return _isBool; }

    inline
    void setIsBool(  bool  __val) { _isBool = __val; }



    inline
    const std::shared_ptr<bool>  & getIsReallyBool() const { return _isReallyBool; }

    inline
    void setIsReallyBool(  std::shared_ptr<bool>   __val) { _isReallyBool = __val; }



    inline
    const int & getNumber() const { return _number; }

    inline
    void setNumber(  int  __val) { _number = __val; }


//ll1gen::getters_end

    Test2Simple & operator = (const Test2Simple & __bean) {
        if(this != &__bean) {
    		    this->_optionalName = __bean._optionalName;

    this->_isBool = __bean._isBool;

    this->_isReallyBool = __bean._isReallyBool;

    this->_number = __bean._number;

//ll1gen::opeq_assign
        }
        return (*this);
    }

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

inline std::ostream& operator<< (std::ostream& __stream, const Test2Simple& __bean) {
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

inline std::istream& operator>> (std::istream& __stream, Test2Simple& __bean) {
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
