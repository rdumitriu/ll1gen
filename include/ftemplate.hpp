
#ifndef _LL1GEN_TEMPLATE_HPP_
#define _LL1GEN_TEMPLATE_HPP_

#include <string>
#include <set>

namespace ll1gen {

///
/// \brief The FTemplate class
///
/// Markers: This looks after comments like //ll1gen::token and appends above the new content
/// Tokens: replace exactly where found
class FTemplate {
public:
    FTemplate(const std::string & _name, const std::string & _initialContent);
    ~FTemplate() {}

    FTemplate(const FTemplate & other);

    FTemplate & operator = (const FTemplate & other);

    void setContent(const std::string & newContent);

    std::string getContent();

    void insertBeforeMarker(const std::string & marker, const std::string & replacement);

    void replaceToken(const std::string & token, const std::string & replacement);

    void addDependent(const std::string & dep);

    std::set<std::string> getDependents();
private:
    std::string name;
    std::string content;
    std::set<std::string> dependents;
};

}

#endif
