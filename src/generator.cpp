
#include <fstream>
#include <sstream>

#include "generator.hpp"


namespace ll1gen {

Generator::Generator(Specification & _spec, const std::string & _baseDirTemplates, const std::string & _outputDir)
                : spec(_spec), baseDirTemplates(_baseDirTemplates), outputDir(_outputDir) {
}

const std::string Generator::getTemplateContent(const std::string & name) {
    auto i = tmpls.find(name);
    if(i == tmpls.end()) {
        throw std::runtime_error("Cannot find template :" + name);
    }
    return i->second;
}

bool Generator::hasTemplate(const std::string & name) {
    auto i = tmpls.find(name);
    return (i != tmpls.end());
}

bool Generator::generate() {
    if(!loadTemplates(tmpls)) {
        addError("Failed to load templates.");
        return false;
    }
    //spec is filled up and checked
    if(!initialize()) {
        addError("Failed to initialize engine.");
        return false;
    }
    bool genok = true;
    for(BeanClazzSpecification & bcs : spec.getBeans()) {
        genok &= processBeanSpecification(bcs);
        if(!genok) { break; }
    }
    if(genok) {
        genok &= createOutput();
    } else {
        addError("Generation of the bean classes failed!");
    }
    return genok;
}

void Generator::addError(const std::string & err) {
    errors.push_back(err);
}

void Generator::printErrors() {
    for(std::string & s : errors) {
        std::cerr << "ERROR: " << s << std::endl;
    }
}

//virtual
bool Generator::initialize() {
    outputDirPath = boost::filesystem::path(outputDir);
    outputDirPath = boost::filesystem::absolute(outputDirPath);
    if(!boost::filesystem::exists(outputDirPath) || !boost::filesystem::is_directory(outputDirPath)) {
        std::ostringstream msg;
        msg << "Directory >>" << outputDirPath << "<< does not exist.";
        addError(msg.str());
        return false;
    }
    return true;
}

//virtual
bool Generator::loadTemplates(std::map<std::string, std::string> & templates) {
    boost::filesystem::path basePath(baseDirTemplates);
    basePath = boost::filesystem::absolute(basePath);
    if(!boost::filesystem::exists(basePath) || !boost::filesystem::is_directory(basePath)) {
        std::ostringstream msg;
        msg << "Directory >>" << basePath << "<< does not exist.";
        addError(msg.str());
        return false;
    }
    boost::filesystem::path templatePath = basePath / "templates" / getName();
    if(!boost::filesystem::exists(templatePath) || !boost::filesystem::is_directory(templatePath)) {
        std::ostringstream msg;
        msg << "Templates directory >>" << templatePath << "<< does not exist.";
        addError(msg.str());
        return false;
    }
    for(const std::string & tmplName : expectedTemplates()) {
        if(!loadTemplateContent(tmplName, templatePath)) {
            std::ostringstream msg;
            msg << "Could not load template >>" << tmplName << "<<. Something was wrong";
            addError(msg.str());
            return false;
        }
    }
    return true;
}

bool Generator::loadTemplateContent(const std::string & tmplName, boost::filesystem::path & templatePath) {
    boost::filesystem::path filePath = templatePath / tmplName;
    if(!boost::filesystem::exists(filePath) || !boost::filesystem::is_regular_file(filePath)) {
        std::ostringstream msg;
        msg << "Could not load template >>" << tmplName << "<<. Not a regular file?";
        addError(msg.str());
        return false;
    }

    std::fstream in(filePath.c_str());
    if(in) {
        std::stringstream buffer;
        buffer << in.rdbuf(); //hell, this is quick and dirty
        tmpls.insert(std::make_pair(tmplName, buffer.str()));
        return true;
    }
    std::ostringstream msg;
    msg << "Could not read template >>" << tmplName << "<<. Perms or bad file?";
    addError(msg.str());
    return false;
}

bool Generator::writeContent(const std::string & fileName, const std::string & content) {
    boost::filesystem::path filePath = outputDirPath / fileName;
    std::fstream out(filePath.c_str(), std::fstream::out);
    out << content;
    return true;
}

}
