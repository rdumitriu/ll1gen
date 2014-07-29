//
// GENERATED by ll1gen : Do not modify (or on your own risk)
//
#ifndef _LL1GEN_GAMERREL_HPP_
#define _LL1GEN_GAMERREL_HPP_

#include "json_utils.hpp"

//ll1gen::include_begin

#include "gamer.hpp"
//ll1gen::include_end

namespace test { namespace gamer { 

class GamerRel {
public:
    //ll1gen::constructor_begin

    //ll1gen::constructor_end
    GamerRel() {}
    ~GamerRel() {}

#ifndef LL1GEN_DISABLE_STANDARD_GETTERS
    //ll1gen::getters_begin

    
    Gamer get_gamer() const { return _gamer; }

    void set_gamer( const Gamer & __val) { _gamer = __val; }



    std::vector<unsigned int>  get_enemyIds() const { return _enemyIds; }

    void set_enemyIds( const std::vector<unsigned int>  & __val) { _enemyIds = __val; }



    std::vector<double>  get_enemyCoords() const { return _enemyCoords; }

    void set_enemyCoords( const std::vector<double>  & __val) { _enemyCoords = __val; }



    std::string get_description() const { return _description; }

    void set_description( const std::string & __val) { _description = __val; }


//ll1gen::getters_end
#endif

#ifndef LL1GEN_DISABLE_REFERENCE_GETTERS
    //ll1gen::ref_getters_begin

        Gamer & gamer() { return _gamer; }


    std::vector<unsigned int>  & enemyIds() { return _enemyIds; }


    std::vector<double>  & enemyCoords() { return _enemyCoords; }


    std::string & description() { return _description; }


//ll1gen::ref_getters_end
#endif

    friend std::ostream& operator<< (std::ostream& __stream, const GamerRel& __bean);
    friend std::istream& operator>> (std::istream& __stream, GamerRel& __bean);
private:
    //ll1gen::field_decl_begin

    Gamer _gamer;
std::vector<unsigned int>  _enemyIds;
std::vector<double>  _enemyCoords;
std::string _description;
//ll1gen::field_decl_end
};

std::ostream& operator<< (std::ostream& __stream, const GamerRel& __bean) {
    __stream << "{";
    //ll1gen::field_ostream_begin

        __stream << "\"gamer\":" << __bean._gamer;


__stream << ",";
    __stream << "\"enemyIds\":";
    ll1gen::json::serializeVector(__stream, __bean._enemyIds);


__stream << ",";
    __stream << "\"enemyCoords\":";
    ll1gen::json::serializeVector(__stream, __bean._enemyCoords);


__stream << ",";
    __stream << "\"description\":\"" << ll1gen::json::detail::encodeJsonString(__bean._description) << "\"";


//ll1gen::field_ostream_end
    __stream << "}";
    return __stream;
}

std::istream& operator>> (std::istream& __stream, GamerRel& __bean) {
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

            if(__propertyName == "gamer") {
        if(!ll1gen::json::detail::lookUpNull(__stream)) {
            __stream >> __bean._gamer;
        } else {
            throw std::runtime_error("JSON: null not supported for field gamer. Check definition");
        }
    }

else
    
    if(__propertyName == "enemyIds") {
        ll1gen::json::deserializeVector(__stream, __bean._enemyIds);
    }

else
    
    if(__propertyName == "enemyCoords") {
        ll1gen::json::deserializeVector(__stream, __bean._enemyCoords);
    }

else
    if(__propertyName == "description") {
        if(!ll1gen::json::detail::parseString(__stream, __bean._description)) {
            throw new std::runtime_error("JSON: null not supported for field description (string). Check definition.");
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