//
// GENERATED by ll1gen : Do not modify (or on your own risk)
//
#ifndef _LL1GEN_MENUROOT_HPP_
#define _LL1GEN_MENUROOT_HPP_

#include "json_utils.hpp"

//ll1gen::include_begin

#include "menu.hpp"
//ll1gen::include_end

namespace test { namespace menu { 

class MenuRoot {
public:
    //ll1gen::constructor_begin

    //ll1gen::constructor_end
    MenuRoot() {}
    ~MenuRoot() {}

#ifndef LL1GEN_DISABLE_STANDARD_GETTERS
    //ll1gen::getters_begin

    
    Menu get_menu() const { return _menu; }

    void set_menu( const Menu & __val) { _menu = __val; }


//ll1gen::getters_end
#endif

#ifndef LL1GEN_DISABLE_REFERENCE_GETTERS
    //ll1gen::ref_getters_begin

        Menu & menu() { return _menu; }


//ll1gen::ref_getters_end
#endif

    friend std::ostream& operator<< (std::ostream& __stream, const MenuRoot& __bean);
    friend std::istream& operator>> (std::istream& __stream, MenuRoot& __bean);
private:
    //ll1gen::field_decl_begin

    Menu _menu;
//ll1gen::field_decl_end
};

std::ostream& operator<< (std::ostream& __stream, const MenuRoot& __bean) {
    __stream << "{";
    //ll1gen::field_ostream_begin

        __stream << "\"menu\":" << __bean._menu;


//ll1gen::field_ostream_end
    __stream << "}";
    return __stream;
}

std::istream& operator>> (std::istream& __stream, MenuRoot& __bean) {
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

            if(__propertyName == "menu") {
        if(!ll1gen::json::detail::lookUpNull(__stream)) {
            __stream >> __bean._menu;
        } else {
            throw std::runtime_error("JSON: null not supported for field menu. Check definition");
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
