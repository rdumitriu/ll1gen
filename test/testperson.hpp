//
// GENERATED by ll1gen : Do not modify (or on your own risk)
//
#ifndef _LL1GEN_TESTPERSON_HPP_
#define _LL1GEN_TESTPERSON_HPP_

#include "json_utils.hpp"

//ll1gen::include_begin

//ll1gen::include_end

namespace test { 

class TestPerson {
public:
    //ll1gen::constructor_begin
    TestPerson(
    		    const std::string & __name

,
     unsigned int  __age

//ll1gen::constructor_param
              ) :
    		    _name(__name)

,
    _age(__age)

//ll1gen::constructor_assign
		{}
    //ll1gen::constructor_begin

    //ll1gen::copy_constructor_begin
    TestPerson(const TestPerson & __bean) :
    		    _name(__bean._name)

,
    _age(__bean._age)

//ll1gen::copy_constructor_assign
		{}
    //ll1gen::copy_constructor_end

    TestPerson() {}
    virtual ~TestPerson() {}

    //ll1gen::getters_begin

    
    const std::string & getName() const { return _name; }

    void setName( const std::string & __val) { _name = __val; }



    const unsigned int & getAge() const { return _age; }

    void setAge(  unsigned int  __val) { _age = __val; }


//ll1gen::getters_end

    TestPerson & operator = (const TestPerson & __bean) {
        if(this != &__bean) {
    		//ll1gen::opeq_end
        }
        return (*this);
    }

    friend std::ostream& operator<< (std::ostream& __stream, const TestPerson& __bean);
    friend std::istream& operator>> (std::istream& __stream, TestPerson& __bean);
private:
    //ll1gen::field_decl_begin

    std::string _name;
unsigned int _age;
//ll1gen::field_decl_end
};

std::ostream& operator<< (std::ostream& __stream, const TestPerson& __bean) {
    __stream << "{";
    //ll1gen::field_ostream_begin

        __stream << "\"name\":\"" << ll1gen::json::detail::encodeJsonString(__bean._name) << "\"";


__stream << ",";
    __stream << "\"age\":" << __bean._age;


//ll1gen::field_ostream_end
    __stream << "}";
    return __stream;
}

std::istream& operator>> (std::istream& __stream, TestPerson& __bean) {
    char __startObjectMrk = ll1gen::json::detail::lookUpAndEat(__stream, "{n");
    if(__startObjectMrk == 'n') {
        ll1gen::json::detail::lookUpTokenRemainder(__stream, __startObjectMrk, "null");
        return __stream;
    }
    for(unsigned int __i = 0; __i < 2; ++__i) {
        ll1gen::json::detail::lookUpAndEat(__stream, "\"");
        std::string __propertyName = ll1gen::json::detail::lookUp(__stream, "\"");
        ll1gen::json::detail::lookUpAndEat(__stream, ":");

        //ll1gen::field_istream_begin

            if(__propertyName == "name") {
        if(!ll1gen::json::detail::parseString(__stream, __bean._name)) {
            throw new std::runtime_error("JSON: null not supported for field name (string). Check definition.");
        }
    }

else
    if(__propertyName == "age") {
        if(!ll1gen::json::detail::lookUpNull(__stream)) {
            __stream >> __bean._age;
        } else {
            throw std::runtime_error("JSON: null not supported for field age. Check definition");
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
