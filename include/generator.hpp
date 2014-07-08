
#ifndef _LL1GEN_GENERATOR_HPP_
#define _LL1GEN_GENERATOR_HPP_

#include <map>
#include <vector>

#include "specification.hpp"
#include <boost/filesystem.hpp>

namespace ll1gen {

class Generator {
public:
    Generator(Specification & _spec, const std::string & baseDirTemplates, const std::string & outputDir);
    virtual ~Generator() {}

    bool generate();

    inline bool hasErrors() { return !errors.empty(); }

    void printErrors();

    virtual std::string getName() = 0;
protected:
    void addError(const std::string & err);

    const std::string getTemplateContent(const std::string & name);
    bool hasTemplate(const std::string & name);

    bool writeContent(const std::string & fileName, const std::string & content);

    virtual bool initialize();
    virtual bool loadTemplates(std::map<std::string, std::string> & templates);

    virtual std::vector<std::string> expectedTemplates() = 0;

    virtual bool processBeanSpecification(BeanClazzSpecification & bcs) = 0;

    virtual bool createOutput() = 0;

    Specification & spec;
private:
    std::string baseDirTemplates;
    std::vector<std::string> errors;
    //expected base templates
    std::map<std::string, std::string> tmpls;

    std::string outputDir;
    boost::filesystem::path outputDirPath;

    bool loadTemplateContent(const std::string & tmplName,
                             boost::filesystem::path & templatePath);
};

}

#endif
