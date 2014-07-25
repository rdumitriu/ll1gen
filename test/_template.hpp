//
// GENERATED : Do not modify (or on your own risk)
//
#ifndef _BEANTEST_HPP_
#define _BEANTEST_HPP_

#include <string>
#include <iostream>
#include "json_utils.hpp"

//ll1gen::include_begin
//ll1gen::include_end

class BeanTest {
public:
    //ll1gen::constructor_begin
    BeanTest(const std::string & _1, double _2, unsigned int _3) : p_s_1(_1), p_d_2(_2), p_ui_3(_3) {}
    //ll1gen::constructor_end
    BeanTest() {}
    ~BeanTest() {}


    //ll1gen::getters_begin
    inline std::string & s() { return p_s_1; }
    inline double & d() { return p_d_2; }
    inline unsigned int & ui() { return p_ui_3; }
    //ll1gen::getters_end

    friend std::ostream& operator<< (std::ostream& stream, const BeanTest& __bean);
    friend std::istream& operator>> (std::istream& stream, BeanTest& __bean);
private:
    //ll1gen::field_decl_begin
    std::string     p_s_1;
    double          p_d_2;
    unsigned int    p_ui_3;
    //ll1gen::field_decl_end
};

std::ostream& operator<< (std::ostream& __stream, const BeanTest& __bean) {
    __stream << "{";
    //ll1gen::field_ostream_begin
    __stream << "\"s\":\"" << ll1gen::json::detail::encodeJsonString(__bean.p_s_1) << "\"";
    __stream << ",";
    __stream << "\"d\":" << __bean.p_d_2;
    __stream << ",";
    __stream << "\"ui\":" << __bean.p_ui_3;
    //ll1gen::field_ostream_end
    __stream << "}";
    return __stream;
}

std::istream& operator>> (std::istream& __stream, BeanTest& __bean) {
    char __startObjectMrk = ll1gen::json::detail::lookUpAndEat(__stream, "{n");
    if(__startObjectMrk == 'n') {
        ll1gen::json::detail::lookUpTokenRemainder(__stream, __startObjectMrk, "null");
        return __stream;
    }
    for(unsigned int __i = 0; __i < 3; ++__i) {
        ll1gen::json::detail::lookUpAndEat(__stream, "\"");
        std::string __propertyName = ll1gen::json::detail::lookUp(__stream, "\"");
        ll1gen::json::detail::lookUpAndEat(__stream, ":");

        //ll1gen::field_istream_begin
        if(__propertyName == "s") {
            ll1gen::json::detail::lookUpAndEat(__stream, "\"");
            __bean.p_s_1 = ll1gen::json::detail::lookUp(__stream, "\"");
        }
        else
        if(__propertyName == "d" && !ll1gen::json::detail::lookUpNull(__stream)) {
            __stream >> __bean.p_d_2;
        }
        else
        if(__propertyName == "ui") {
            __stream >> __bean.p_ui_3;
        }
        //ll1gen::field_istream_end
        if('}' == ll1gen::json::detail::lookUpAndEat(__stream, "},")) {
            break;
        }
    }
    return __stream;
}

#endif
