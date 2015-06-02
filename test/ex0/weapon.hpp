//
// GENERATED by ll1gen : Do not modify (or on your own risk)
//
#ifndef _LL1GEN_WEAPON_HPP_
#define _LL1GEN_WEAPON_HPP_

#include "json_utils.hpp"

//ll1gen::include_begin

//ll1gen::include_end

namespace test { namespace gamer { 

class Weapon {
public:
    //ll1gen::constructor_begin
    Weapon(
    		    const std::string & __name

,
     double  __damage

//ll1gen::constructor_param
              ) :
    		    _name(__name)

,
    _damage(__damage)

//ll1gen::constructor_assign
		{}
    //ll1gen::constructor_begin

    //ll1gen::copy_constructor_begin
    Weapon(const Weapon & __bean) :
    		    _name(__bean._name)

,
    _damage(__bean._damage)

//ll1gen::copy_constructor_assign
		{}
    //ll1gen::copy_constructor_end

    Weapon() {}
    virtual ~Weapon() {}

    //ll1gen::getters_begin

    
    inline
    const std::string & getName() const { return _name; }

    inline
    void setName( const std::string & __val) { _name = __val; }



    inline
    const double & getDamage() const { return _damage; }

    inline
    void setDamage(  double  __val) { _damage = __val; }


//ll1gen::getters_end

    Weapon & operator = (const Weapon & __bean) {
        if(this != &__bean) {
    		    this->_name = __bean._name;

    this->_damage = __bean._damage;

//ll1gen::opeq_assign
        }
        return (*this);
    }

    friend std::ostream& operator<< (std::ostream& __stream, const Weapon& __bean);
    friend std::istream& operator>> (std::istream& __stream, Weapon& __bean);
private:
    //ll1gen::field_decl_begin

    std::string _name;
double _damage;
//ll1gen::field_decl_end
};

inline std::ostream& operator<< (std::ostream& __stream, const Weapon& __bean) {
    __stream << "{";
    //ll1gen::field_ostream_begin

        __stream << "\"name\":\"" << ll1gen::json::detail::encodeJsonString(__bean._name) << "\"";


__stream << ",";
    __stream << "\"damage\":" << __bean._damage;


//ll1gen::field_ostream_end
    __stream << "}";
    return __stream;
}

inline std::istream& operator>> (std::istream& __stream, Weapon& __bean) {
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
    if(__propertyName == "damage") {
        if(!ll1gen::json::detail::lookUpNull(__stream)) {
            __stream >> __bean._damage;
        } else {
            throw std::runtime_error("JSON: null not supported for field damage. Check definition");
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
