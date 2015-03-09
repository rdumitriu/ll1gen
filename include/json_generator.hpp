
#ifndef _LL1GEN_JSON_GENERATOR_HPP_
#define _LL1GEN_JSON_GENERATOR_HPP_


#include "generator.hpp"
#include "ftemplate.hpp"

namespace ll1gen {

class JsonGenerator : public Generator {
public:
    JsonGenerator(Specification & _spec, const std::string & baseDirTemplates, const std::string & outputDir) :
        Generator(_spec, baseDirTemplates, outputDir) {}
    virtual ~JsonGenerator() {}

    virtual std::string getName();

protected:
    virtual std::vector<std::string> expectedTemplates();

    virtual bool processBeanSpecification(BeanClazzSpecification & bcs);

    virtual bool createOutput();

private:
    std::map<std::string, FTemplate> outputTemplates;

    bool registerOutputTemplate(const std::string & name, const std::string & content);

    bool isOutputTemplateRegistered(const std::string & name);

    FTemplate & getTemplate(const std::string & beanName);

    bool processBeanFieldsSpecification(FTemplate & t, BeanClazzSpecification & bcs);

    bool processFieldSpecification(unsigned int ndx, FTemplate & t,
                                   FieldSpecification & fs, BeanClazzSpecification & bcs);

    bool createImportList(FTemplate & t);

    std::string toFileName(const std::string & s);
};

}

#endif
