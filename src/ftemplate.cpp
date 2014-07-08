
#include "ftemplate.hpp"

#include <sstream>

#include <boost/algorithm/string.hpp>

namespace ll1gen {

FTemplate::FTemplate(const std::string & _name, const std::string & _initialContent)
                            : name(_name), content(_initialContent) {}

FTemplate::FTemplate(const FTemplate & other) {
    name = other.name;
    content = other.content;
}

FTemplate & FTemplate::operator = (const FTemplate & other) {
    if(this != &other) {
        name = other.name;
        content = other.content;
    }
    return (*this);
}

void FTemplate::setContent(const std::string & newContent) {
    content = newContent;
}

std::string FTemplate::getContent() {
    return content;
}

void FTemplate::addDependent(const std::string & dep) {
    dependents.insert(dep);
}

std::set<std::string> FTemplate::getDependents() {
    return dependents;
}

void FTemplate::insertBeforeMarker(const std::string & marker, const std::string & replacement) {
    std::string realToken = "//ll1gen::" + marker;
    std::size_t found = content.find(realToken);
    if(found != std::string::npos) {
        std::ostringstream repl;
        repl << replacement << std::endl;
        content.insert(found, repl.str());
    }
}

void FTemplate::replaceToken(const std::string & token, const std::string & replacement) {
    boost::replace_all(content, "$" + token + "$", replacement);
}

}
