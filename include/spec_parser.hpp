
#ifndef _LL1GEN_SPECPARSER_HPP_
#define _LL1GEN_SPECPARSER_HPP_

#include <string>
#include <vector>

#include "specification.hpp"

namespace ll1gen {

class SpecificationParser {
public:
    explicit SpecificationParser(Specification & _spec) : spec(_spec) {}
    ~SpecificationParser() {}

    SpecificationParser(const SpecificationParser & other) = delete;
    SpecificationParser & operator = (const SpecificationParser & other) = delete;

    bool parse(std::istream & in);

    void printErrors();

private:

    struct ErrorLine {
        unsigned int line;
        std::string msg;
    };

    Specification & spec;
    std::vector<ErrorLine> errs;
    std::string lastError;

    bool processLine(int line, const std::string & s);
    bool processNamespace(const std::string & s);
    bool processClassDefinition(const std::string & s);
    bool processFieldDefinition(const std::string & s);


    bool isIdentifier(const std::string & s);
    void addError(unsigned int line);
};

}

#endif
