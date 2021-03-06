//
// GENERATED by ll1gen : Do not modify (or on your own risk)
//
#ifndef _LL1GEN_GLOSSARYLIST_HPP_
#define _LL1GEN_GLOSSARYLIST_HPP_

#include "json_utils.hpp"

//ll1gen::include_begin

#include "glossaryentry.hpp"
//ll1gen::include_end

namespace test { namespace glossary { 

class GlossaryList {
public:
    //ll1gen::constructor_begin
    GlossaryList(
    		    const GlossaryEntry & __GlossEntry

//ll1gen::constructor_param
              ) :
    		    _GlossEntry(__GlossEntry)

//ll1gen::constructor_assign
		{}
    //ll1gen::constructor_begin

    //ll1gen::copy_constructor_begin
    GlossaryList(const GlossaryList & __bean) :
    		    _GlossEntry(__bean._GlossEntry)

//ll1gen::copy_constructor_assign
		{}
    //ll1gen::copy_constructor_end

    GlossaryList() {}
    virtual ~GlossaryList() {}

    //ll1gen::getters_begin

    
    inline
    const GlossaryEntry & getGlossEntry() const { return _GlossEntry; }

    inline
    void setGlossEntry( const GlossaryEntry & __val) { _GlossEntry = __val; }


//ll1gen::getters_end

    GlossaryList & operator = (const GlossaryList & __bean) {
        if(this != &__bean) {
    		    this->_GlossEntry = __bean._GlossEntry;

//ll1gen::opeq_assign
        }
        return (*this);
    }

    friend std::ostream& operator<< (std::ostream& __stream, const GlossaryList& __bean);
    friend std::istream& operator>> (std::istream& __stream, GlossaryList& __bean);
private:
    //ll1gen::field_decl_begin

    GlossaryEntry _GlossEntry;
//ll1gen::field_decl_end
};

inline std::ostream& operator<< (std::ostream& __stream, const GlossaryList& __bean) {
    __stream << "{";
    //ll1gen::field_ostream_begin

        __stream << "\"GlossEntry\":" << __bean._GlossEntry;


//ll1gen::field_ostream_end
    __stream << "}";
    return __stream;
}

inline std::istream& operator>> (std::istream& __stream, GlossaryList& __bean) {
    char __startObjectMrk = ll1gen::json::detail::lookUpAndEat(__stream, "{n");
    if(__startObjectMrk == 'n') {
        ll1gen::json::detail::lookUpTokenRemainder(__stream, __startObjectMrk, "null");
        return __stream;
    }
    for(unsigned int __i = 0; __i < 1; ++__i) {
        ll1gen::json::detail::lookUpAndEat(__stream, "\"");
        std::string __propertyName = ll1gen::json::detail::lookUp(__stream, "\"");
        ll1gen::json::detail::lookUpAndEat(__stream, ":");

        //ll1gen::field_istream_begin

            if(__propertyName == "GlossEntry") {
        if(!ll1gen::json::detail::lookUpNull(__stream)) {
            __stream >> __bean._GlossEntry;
        } else {
            throw std::runtime_error("JSON: null not supported for field GlossEntry. Check definition");
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
