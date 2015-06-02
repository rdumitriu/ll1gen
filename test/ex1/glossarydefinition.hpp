//
// GENERATED by ll1gen : Do not modify (or on your own risk)
//
#ifndef _LL1GEN_GLOSSARYDEFINITION_HPP_
#define _LL1GEN_GLOSSARYDEFINITION_HPP_

#include "json_utils.hpp"

//ll1gen::include_begin

//ll1gen::include_end

namespace test { namespace glossary { 

class GlossaryDefinition {
public:
    //ll1gen::constructor_begin
    GlossaryDefinition(
    		    const std::string & __para

,
    const std::vector<std::string>  & __GlossSeeAlso

//ll1gen::constructor_param
              ) :
    		    _para(__para)

,
    _GlossSeeAlso(__GlossSeeAlso)

//ll1gen::constructor_assign
		{}
    //ll1gen::constructor_begin

    //ll1gen::copy_constructor_begin
    GlossaryDefinition(const GlossaryDefinition & __bean) :
    		    _para(__bean._para)

,
    _GlossSeeAlso(__bean._GlossSeeAlso)

//ll1gen::copy_constructor_assign
		{}
    //ll1gen::copy_constructor_end

    GlossaryDefinition() {}
    virtual ~GlossaryDefinition() {}

    //ll1gen::getters_begin

    
    inline
    const std::string & getPara() const { return _para; }

    inline
    void setPara( const std::string & __val) { _para = __val; }



    inline
    const std::vector<std::string>  & getGlossSeeAlso() const { return _GlossSeeAlso; }

    inline
    void setGlossSeeAlso( const std::vector<std::string>  & __val) { _GlossSeeAlso = __val; }


//ll1gen::getters_end

    GlossaryDefinition & operator = (const GlossaryDefinition & __bean) {
        if(this != &__bean) {
    		    this->_para = __bean._para;

    this->_GlossSeeAlso = __bean._GlossSeeAlso;

//ll1gen::opeq_assign
        }
        return (*this);
    }

    friend std::ostream& operator<< (std::ostream& __stream, const GlossaryDefinition& __bean);
    friend std::istream& operator>> (std::istream& __stream, GlossaryDefinition& __bean);
private:
    //ll1gen::field_decl_begin

    std::string _para;
std::vector<std::string>  _GlossSeeAlso;
//ll1gen::field_decl_end
};

inline std::ostream& operator<< (std::ostream& __stream, const GlossaryDefinition& __bean) {
    __stream << "{";
    //ll1gen::field_ostream_begin

        __stream << "\"para\":\"" << ll1gen::json::detail::encodeJsonString(__bean._para) << "\"";


__stream << ",";
    __stream << "\"GlossSeeAlso\":";
    ll1gen::json::serializeVector(__stream, __bean._GlossSeeAlso);


//ll1gen::field_ostream_end
    __stream << "}";
    return __stream;
}

inline std::istream& operator>> (std::istream& __stream, GlossaryDefinition& __bean) {
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

            if(__propertyName == "para") {
        if(!ll1gen::json::detail::parseString(__stream, __bean._para)) {
            throw new std::runtime_error("JSON: null not supported for field para (string). Check definition.");
        }
    }

else
    
    if(__propertyName == "GlossSeeAlso") {
        ll1gen::json::deserializeVector(__stream, __bean._GlossSeeAlso);
    }

//ll1gen::field_istream_end

        if('}' == ll1gen::json::detail::lookUpAndEat(__stream, "},")) {
            break;
        }
    }
    return __stream;
}

} } 

#endif
