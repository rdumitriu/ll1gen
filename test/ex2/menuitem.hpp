//
// GENERATED by ll1gen : Do not modify (or on your own risk)
//
#ifndef _LL1GEN_MENUITEM_HPP_
#define _LL1GEN_MENUITEM_HPP_

#include "json_utils.hpp"

//ll1gen::include_begin

//ll1gen::include_end

namespace test { namespace menu { 

class MenuItem {
public:
    //ll1gen::constructor_begin
    MenuItem(
    		    const std::string & __id

,
    const std::string & __label

//ll1gen::constructor_param
              ) :
    		    _id(__id)

,
    _label(__label)

//ll1gen::constructor_assign
		{}
    //ll1gen::constructor_begin

    //ll1gen::copy_constructor_begin
    MenuItem(const MenuItem & __bean) :
    		    _id(__bean._id)

,
    _label(__bean._label)

//ll1gen::copy_constructor_assign
		{}
    //ll1gen::copy_constructor_end

    MenuItem() {}
    virtual ~MenuItem() {}

    //ll1gen::getters_begin

    
    inline
    const std::string & getId() const { return _id; }

    inline
    void setId( const std::string & __val) { _id = __val; }



    inline
    const std::string & getLabel() const { return _label; }

    inline
    void setLabel( const std::string & __val) { _label = __val; }


//ll1gen::getters_end

    MenuItem & operator = (const MenuItem & __bean) {
        if(this != &__bean) {
    		    this->_id = __bean._id;

    this->_label = __bean._label;

//ll1gen::opeq_assign
        }
        return (*this);
    }

    friend std::ostream& operator<< (std::ostream& __stream, const MenuItem& __bean);
    friend std::istream& operator>> (std::istream& __stream, MenuItem& __bean);
private:
    //ll1gen::field_decl_begin

    std::string _id;
std::string _label;
//ll1gen::field_decl_end
};

inline std::ostream& operator<< (std::ostream& __stream, const MenuItem& __bean) {
    __stream << "{";
    //ll1gen::field_ostream_begin

        __stream << "\"id\":\"" << ll1gen::json::detail::encodeJsonString(__bean._id) << "\"";


__stream << ",";
    __stream << "\"label\":\"" << ll1gen::json::detail::encodeJsonString(__bean._label) << "\"";


//ll1gen::field_ostream_end
    __stream << "}";
    return __stream;
}

inline std::istream& operator>> (std::istream& __stream, MenuItem& __bean) {
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

            if(__propertyName == "id") {
        if(!ll1gen::json::detail::parseString(__stream, __bean._id)) {
            throw new std::runtime_error("JSON: null not supported for field id (string). Check definition.");
        }
    }

else
    if(__propertyName == "label") {
        if(!ll1gen::json::detail::parseString(__stream, __bean._label)) {
            throw new std::runtime_error("JSON: null not supported for field label (string). Check definition.");
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
