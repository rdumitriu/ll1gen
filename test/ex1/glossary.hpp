//
// GENERATED by ll1gen : Do not modify (or on your own risk)
//
#ifndef _LL1GEN_GLOSSARY_HPP_
#define _LL1GEN_GLOSSARY_HPP_

#include "json_utils.hpp"

//ll1gen::include_begin

#include "glossarydiv.hpp"
//ll1gen::include_end

namespace test { namespace glossary { 

class Glossary {
public:
    //ll1gen::constructor_begin
    Glossary(
    		    const std::string & __title

,
    const GlossaryDiv & __GlossDiv

//ll1gen::constructor_param
              ) :
    		    _title(__title)

,
    _GlossDiv(__GlossDiv)

//ll1gen::constructor_assign
		{}
    //ll1gen::constructor_begin

    //ll1gen::copy_constructor_begin
    Glossary(const Glossary & __bean) :
    		    _title(__bean._title)

,
    _GlossDiv(__bean._GlossDiv)

//ll1gen::copy_constructor_assign
		{}
    //ll1gen::copy_constructor_end

    Glossary() {}
    virtual ~Glossary() {}

    //ll1gen::getters_begin

    
    inline
    const std::string & getTitle() const { return _title; }

    inline
    void setTitle( const std::string & __val) { _title = __val; }



    inline
    const GlossaryDiv & getGlossDiv() const { return _GlossDiv; }

    inline
    void setGlossDiv( const GlossaryDiv & __val) { _GlossDiv = __val; }


//ll1gen::getters_end

    Glossary & operator = (const Glossary & __bean) {
        if(this != &__bean) {
    		    this->_title = __bean._title;

    this->_GlossDiv = __bean._GlossDiv;

//ll1gen::opeq_assign
        }
        return (*this);
    }

    friend std::ostream& operator<< (std::ostream& __stream, const Glossary& __bean);
    friend std::istream& operator>> (std::istream& __stream, Glossary& __bean);
private:
    //ll1gen::field_decl_begin

    std::string _title;
GlossaryDiv _GlossDiv;
//ll1gen::field_decl_end
};

inline std::ostream& operator<< (std::ostream& __stream, const Glossary& __bean) {
    __stream << "{";
    //ll1gen::field_ostream_begin

        __stream << "\"title\":\"" << ll1gen::json::detail::encodeJsonString(__bean._title) << "\"";


__stream << ",";
    __stream << "\"GlossDiv\":" << __bean._GlossDiv;


//ll1gen::field_ostream_end
    __stream << "}";
    return __stream;
}

inline std::istream& operator>> (std::istream& __stream, Glossary& __bean) {
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

            if(__propertyName == "title") {
        if(!ll1gen::json::detail::parseString(__stream, __bean._title)) {
            throw new std::runtime_error("JSON: null not supported for field title (string). Check definition.");
        }
    }

else
    if(__propertyName == "GlossDiv") {
        if(!ll1gen::json::detail::lookUpNull(__stream)) {
            __stream >> __bean._GlossDiv;
        } else {
            throw std::runtime_error("JSON: null not supported for field GlossDiv. Check definition");
        }
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
