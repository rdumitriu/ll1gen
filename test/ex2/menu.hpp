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

    //ll1gen::constructor_end
    Menu() {}
    ~Menu() {}

#ifndef LL1GEN_DISABLE_STANDARD_GETTERS
    //ll1gen::getters_begin

    
    std::string get_header() const { return _header; }

    void set_header( const std::string & __val) { _header = __val; }



    std::vector<std::shared_ptr<MenuItem>> get_items() const { return _items; }

    void set_items( const std::vector<std::shared_ptr<MenuItem>> & __val) { _items = __val; }


//ll1gen::getters_end
#endif

#ifndef LL1GEN_DISABLE_REFERENCE_GETTERS
    //ll1gen::ref_getters_begin

        std::string & header() { return _header; }


    std::vector<std::shared_ptr<MenuItem>> & items() { return _items; }


//ll1gen::ref_getters_end
#endif

    friend std::ostream& operator<< (std::ostream& __stream, const Menu& __bean);
    friend std::istream& operator>> (std::istream& __stream, Menu& __bean);
private:
    //ll1gen::field_decl_begin

    std::string _header;
std::vector<std::shared_ptr<MenuItem>> _items;
//ll1gen::field_decl_end
};

std::ostream& operator<< (std::ostream& __stream, const Menu& __bean) {
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

std::istream& operator>> (std::istream& __stream, Menu& __bean) {
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