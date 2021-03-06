//
// GENERATED by ll1gen : Do not modify (or on your own risk)
//
#ifndef _LL1GEN_MENU_HPP_
#define _LL1GEN_MENU_HPP_

#include "json_utils.hpp"

//ll1gen::include_begin

#include "menuitem.hpp"
//ll1gen::include_end

namespace test { namespace menu { 

class Menu {
public:
    //ll1gen::constructor_begin
    Menu(
    		    const std::string & __header

,
    const std::vector<std::shared_ptr<MenuItem>> & __items

//ll1gen::constructor_param
              ) :
    		    _header(__header)

,
    _items(__items)

//ll1gen::constructor_assign
		{}
    //ll1gen::constructor_begin

    //ll1gen::copy_constructor_begin
    Menu(const Menu & __bean) :
    		    _header(__bean._header)

,
    _items(__bean._items)

//ll1gen::copy_constructor_assign
		{}
    //ll1gen::copy_constructor_end

    Menu() {}
    virtual ~Menu() {}

    //ll1gen::getters_begin

    
    inline
    const std::string & getHeader() const { return _header; }

    inline
    void setHeader( const std::string & __val) { _header = __val; }



    inline
    const std::vector<std::shared_ptr<MenuItem>> & getItems() const { return _items; }

    inline
    void setItems( const std::vector<std::shared_ptr<MenuItem>> & __val) { _items = __val; }


//ll1gen::getters_end

    Menu & operator = (const Menu & __bean) {
        if(this != &__bean) {
    		    this->_header = __bean._header;

    this->_items = __bean._items;

//ll1gen::opeq_assign
        }
        return (*this);
    }

    friend std::ostream& operator<< (std::ostream& __stream, const Menu& __bean);
    friend std::istream& operator>> (std::istream& __stream, Menu& __bean);
private:
    //ll1gen::field_decl_begin

    std::string _header;
std::vector<std::shared_ptr<MenuItem>> _items;
//ll1gen::field_decl_end
};

inline std::ostream& operator<< (std::ostream& __stream, const Menu& __bean) {
    __stream << "{";
    //ll1gen::field_ostream_begin

        __stream << "\"header\":\"" << ll1gen::json::detail::encodeJsonString(__bean._header) << "\"";


__stream << ",";
    __stream << "\"items\":";
    ll1gen::json::serializeRefVector(__stream, __bean._items);


//ll1gen::field_ostream_end
    __stream << "}";
    return __stream;
}

inline std::istream& operator>> (std::istream& __stream, Menu& __bean) {
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

            if(__propertyName == "header") {
        if(!ll1gen::json::detail::parseString(__stream, __bean._header)) {
            throw new std::runtime_error("JSON: null not supported for field header (string). Check definition.");
        }
    }

else
    
    if(__propertyName == "items") {
	ll1gen::json::deserializeRefVector(__stream, __bean._items);
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
