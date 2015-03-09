//
// GENERATED by ll1gen : Do not modify (or on your own risk)
//
#ifndef _LL1GEN_GAMER_HPP_
#define _LL1GEN_GAMER_HPP_

#include "json_utils.hpp"

//ll1gen::include_begin

#include "score.hpp"
#include "weapon.hpp"
//ll1gen::include_end

namespace test { namespace gamer { 

class Gamer {
public:
    //ll1gen::constructor_begin
    Gamer(
    		    const std::string & __name

,
     unsigned int  __age

,
     std::shared_ptr<Weapon>   __weapon

,
    const Score & __score

//ll1gen::constructor_param
              ) :
    		    _name(__name)

,
    _age(__age)

,
    _weapon(__weapon)

,
    _score(__score)

//ll1gen::constructor_assign
		{}
    //ll1gen::constructor_begin

    //ll1gen::copy_constructor_begin
    Gamer(const Gamer & __bean) :
    		    _name(__bean._name)

,
    _age(__bean._age)

,
    _weapon(__bean._weapon)

,
    _score(__bean._score)

//ll1gen::copy_constructor_assign
		{}
    //ll1gen::copy_constructor_end

    Gamer() {}
    virtual ~Gamer() {}

    //ll1gen::getters_begin

    
    const std::string & getName() const { return _name; }

    void setName( const std::string & __val) { _name = __val; }



    const unsigned int & getAge() const { return _age; }

    void setAge(  unsigned int  __val) { _age = __val; }



    const std::shared_ptr<Weapon>  & getWeapon() const { return _weapon; }

    void setWeapon(  std::shared_ptr<Weapon>   __val) { _weapon = __val; }



    const Score & getScore() const { return _score; }

    void setScore( const Score & __val) { _score = __val; }


//ll1gen::getters_end

    Gamer & operator = (const Gamer & __bean) {
        if(this != &__bean) {
    		    this->_name = __bean._name;

    this->_age = __bean._age;

    this->_weapon = __bean._weapon;

    this->_score = __bean._score;

//ll1gen::opeq_assign
        }
        return (*this);
    }

    friend std::ostream& operator<< (std::ostream& __stream, const Gamer& __bean);
    friend std::istream& operator>> (std::istream& __stream, Gamer& __bean);
private:
    //ll1gen::field_decl_begin

    std::string _name;
unsigned int _age;
std::shared_ptr<Weapon>  _weapon;
Score _score;
//ll1gen::field_decl_end
};

std::ostream& operator<< (std::ostream& __stream, const Gamer& __bean) {
    __stream << "{";
    //ll1gen::field_ostream_begin

        __stream << "\"name\":\"" << ll1gen::json::detail::encodeJsonString(__bean._name) << "\"";


__stream << ",";
    __stream << "\"age\":" << __bean._age;


__stream << ",";
    if(__bean._weapon.get()) {
        __stream << "\"weapon\":" << *(__bean._weapon);
    } else {
        __stream << "\"weapon\": null";
    }


__stream << ",";
    __stream << "\"score\":" << __bean._score;


//ll1gen::field_ostream_end
    __stream << "}";
    return __stream;
}

std::istream& operator>> (std::istream& __stream, Gamer& __bean) {
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

else
    if(__propertyName == "weapon") {
        __bean._weapon = std::make_shared<Weapon>();
        if(!ll1gen::json::detail::lookUpNull(__stream)) {
            __stream >> *(__bean._weapon);
        } else {
            __bean._weapon.reset();
        }
    }

else
    if(__propertyName == "score") {
        if(!ll1gen::json::detail::lookUpNull(__stream)) {
            __stream >> __bean._score;
        } else {
            throw std::runtime_error("JSON: null not supported for field score. Check definition");
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
