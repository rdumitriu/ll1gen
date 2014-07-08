
#ifndef _LL1GEN_SPECIFICATION_HPP_
#define _LL1GEN_SPECIFICATION_HPP_

#include <string>
#include <vector>


namespace ll1gen {

enum FieldFlags {
    F_VECTOR = 0x1,
    F_POINTER = 0x2
};

struct FieldSpecification {
    FieldSpecification(const std::string & _name, const std::string & _type, unsigned int _flags)
                                                    : name(_name), type(_type), flags(_flags) {}
    ~FieldSpecification() {}

    std::string name;
    std::string type;
    unsigned int flags;
};

class BeanClazzSpecification {
public:
    BeanClazzSpecification(std::string & _name) : name(_name) {}
    ~BeanClazzSpecification() {}

    inline std::string & getName() { return name; }

    inline std::vector<FieldSpecification> & getFields() { return fieldSpecs; }

private:
    std::string name;
    std::vector<FieldSpecification> fieldSpecs;
};

class Specification {
public:
    Specification() {}
    ~Specification() {}

    inline std::vector<std::string> & getNamespaces() { return namespaces; }

    inline std::vector<BeanClazzSpecification> & getBeans() { return beans; }

    inline BeanClazzSpecification & getLastBean() { return beans.at(beans.size() - 1); }

private:
    std::vector<std::string> namespaces;
    std::vector<BeanClazzSpecification> beans;
};


}

#endif
