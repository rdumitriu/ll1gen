//
// GENERATED by ll1gen : Do not modify (or on your own risk)
//
#ifndef _LL1GEN_TESTNEVECS_HPP_
#define _LL1GEN_TESTNEVECS_HPP_

#include "json_utils.hpp"

//ll1gen::include_begin

#include "testperson.hpp"
//ll1gen::include_end

namespace test { 

class TestNEVecs {
public:
    //ll1gen::constructor_begin
    TestNEVecs(
    		    const std::vector<std::shared_ptr<bool>> & __boolVec

,
    const std::vector<std::shared_ptr<std::string>> & __stringVec

,
    const std::vector<std::shared_ptr<int>> & __intVec

,
    const std::vector<std::shared_ptr<TestPerson>> & __objVec

//ll1gen::constructor_param
              ) :
    		    _boolVec(__boolVec)

,
    _stringVec(__stringVec)

,
    _intVec(__intVec)

,
    _objVec(__objVec)

//ll1gen::constructor_assign
		{}
    //ll1gen::constructor_begin

    //ll1gen::copy_constructor_begin
    TestNEVecs(const TestNEVecs & __bean) :
    		    _boolVec(__bean._boolVec)

,
    _stringVec(__bean._stringVec)

,
    _intVec(__bean._intVec)

,
    _objVec(__bean._objVec)

//ll1gen::copy_constructor_assign
		{}
    //ll1gen::copy_constructor_end

    TestNEVecs() {}
    virtual ~TestNEVecs() {}

    //ll1gen::getters_begin

    
    inline
    const std::vector<std::shared_ptr<bool>> & getBoolVec() const { return _boolVec; }

    inline
    void setBoolVec( const std::vector<std::shared_ptr<bool>> & __val) { _boolVec = __val; }



    inline
    const std::vector<std::shared_ptr<std::string>> & getStringVec() const { return _stringVec; }

    inline
    void setStringVec( const std::vector<std::shared_ptr<std::string>> & __val) { _stringVec = __val; }



    inline
    const std::vector<std::shared_ptr<int>> & getIntVec() const { return _intVec; }

    inline
    void setIntVec( const std::vector<std::shared_ptr<int>> & __val) { _intVec = __val; }



    inline
    const std::vector<std::shared_ptr<TestPerson>> & getObjVec() const { return _objVec; }

    inline
    void setObjVec( const std::vector<std::shared_ptr<TestPerson>> & __val) { _objVec = __val; }


//ll1gen::getters_end

    TestNEVecs & operator = (const TestNEVecs & __bean) {
        if(this != &__bean) {
    		    this->_boolVec = __bean._boolVec;

    this->_stringVec = __bean._stringVec;

    this->_intVec = __bean._intVec;

    this->_objVec = __bean._objVec;

//ll1gen::opeq_assign
        }
        return (*this);
    }

    friend std::ostream& operator<< (std::ostream& __stream, const TestNEVecs& __bean);
    friend std::istream& operator>> (std::istream& __stream, TestNEVecs& __bean);
private:
    //ll1gen::field_decl_begin

    std::vector<std::shared_ptr<bool>> _boolVec;
std::vector<std::shared_ptr<std::string>> _stringVec;
std::vector<std::shared_ptr<int>> _intVec;
std::vector<std::shared_ptr<TestPerson>> _objVec;
//ll1gen::field_decl_end
};

inline std::ostream& operator<< (std::ostream& __stream, const TestNEVecs& __bean) {
    __stream << "{";
    //ll1gen::field_ostream_begin

        __stream << "\"boolVec\":";
    ll1gen::json::serializeRefVector(__stream, __bean._boolVec);

__stream << ",";
    __stream << "\"stringVec\":";
    ll1gen::json::serializeRefVector(__stream, __bean._stringVec);



__stream << ",";
    __stream << "\"intVec\":";
    ll1gen::json::serializeRefVector(__stream, __bean._intVec);


__stream << ",";
    __stream << "\"objVec\":";
    ll1gen::json::serializeRefVector(__stream, __bean._objVec);


//ll1gen::field_ostream_end
    __stream << "}";
    return __stream;
}

inline std::istream& operator>> (std::istream& __stream, TestNEVecs& __bean) {
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

            
    if(__propertyName == "boolVec") {
        ll1gen::json::deserializeRefVector(__stream, __bean._boolVec);
    }

else
    
    if(__propertyName == "stringVec") {
        ll1gen::json::deserializeRefVector(__stream, __bean._stringVec);
    }

else
    
    if(__propertyName == "intVec") {
	ll1gen::json::deserializeRefVector(__stream, __bean._intVec);
    }

else
    
    if(__propertyName == "objVec") {
	ll1gen::json::deserializeRefVector(__stream, __bean._objVec);
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
