
#include <sstream>

#include "json_generator.hpp"

#include <boost/algorithm/string.hpp>

namespace ll1gen {

//virtual
std::string JsonGenerator::getName() {
    return "json";
}

//virtual
std::vector<std::string> JsonGenerator::expectedTemplates() {
    std::vector<std::string> ret;
    ret.push_back("json_utils.hpp"); //*
    ret.push_back("json_bean_template.t"); //*
    ret.push_back("ref_getter_content.t"); //*
    ret.push_back("std_getter_content.t"); //*

    ret.push_back("serialize_normal_field.t"); //*
//    ret.push_back("deserialize_normal_field.t");

    ret.push_back("serialize_ref_vector.t"); //*
//    ret.push_back("deserialize_ref_vector.t");

    ret.push_back("serialize_ref_vector_string.t"); //*
//    ret.push_back("deserialize_ref_vector_string.t");

    ret.push_back("serialize_ref_vector_bool.t"); //*
//    ret.push_back("deserialize_ref_vector_bool.t");

    ret.push_back("serialize_sptr_normal_field.t"); //*
//    ret.push_back("deserialize_sptr_normal_field.t");

    ret.push_back("serialize_sptr_string.t"); //*
//    ret.push_back("deserialize_sptr_string.t");

    ret.push_back("serialize_sptr_bool.t"); //*
//    ret.push_back("deserialize_sptr_bool.t");

    ret.push_back("serialize_vector_bool.t"); //*
//    ret.push_back("deserialize_vector_bool.t");

    ret.push_back("serialize_vector_string.t"); //*
//    ret.push_back("deserialize_vector_string.t");

    ret.push_back("serialize_vector.t"); //*
//    ret.push_back("deserialize_vector.t");

    ret.push_back("serialize_string.t"); //*
//    ret.push_back("deserialize_string.t");

    ret.push_back("serialize_bool.t"); //*
//    ret.push_back("deserialize_bool.t");

    return ret;
}

//virtual
bool JsonGenerator::processBeanSpecification(BeanClazzSpecification & bcs) {
    std::string content = getTemplateContent("json_bean_template.t");
    if(bcs.getFields().size() == 0) {
        std::ostringstream msg;
        msg << "Bean " << bcs.getName() << " has no fields ?!?";
        addError(msg.str());
        return false;
    }
    if(!registerOutputTemplate(bcs.getName(), content)) {
        return false;
    }
    std::cout << "Generating bean file : " << bcs.getName() << std::endl;

    //1: replace the names
    std::string beanName = bcs.getName();
    FTemplate & t = getTemplate(beanName);

    std::string lowercaseName = boost::to_lower_copy(beanName);
    std::string uppercaseName = boost::to_upper_copy(beanName);
    t.replaceToken("BEANNAME", uppercaseName);
    t.replaceToken("beanname", lowercaseName);
    t.replaceToken("BeanName", beanName);

    //2: fix the namespaces
    std::string namespaceBegin;
    std::string namespaceEnd;
    for(auto & s : spec.getNamespaces()) {
        namespaceBegin.append("namespace ").append(s).append(" { ");
        namespaceEnd.append("} ");
    }
    t.replaceToken("namespace_def_begin", namespaceBegin);
    t.replaceToken("namespace_def_end", namespaceEnd);

    std::ostringstream n;
    n << bcs.getFields().size();
    t.replaceToken("bean_number_of_fields", n.str());

    //3: process the fields
    return processBeanFieldsSpecification(t, bcs);
}

bool JsonGenerator::processBeanFieldsSpecification(FTemplate & t, BeanClazzSpecification & bcs) {
    unsigned int i = 0;
    for(FieldSpecification & fs : bcs.getFields()) {
        if(!processFieldSpecification(i, t, fs, bcs)) {
            return false;
        }
        i++;
    }
    return createFullFieldConstructor(t, bcs) &&
           createImportList(t, bcs);
}

bool JsonGenerator::processFieldSpecification(unsigned int ndx, FTemplate & t,
                                              FieldSpecification & fs,
                                              BeanClazzSpecification & bcs) {
    //WARNING: muddy code ahead
    //0: create initially the little pieces
    std::string realType = fs.type;
    if(realType == "string") {
        realType = "std::string";
    }
    std::string varName = "_" + fs.name;
    std::string typeDecl = realType;
    std::string typeSetPredecl = "";
    std::string typeSetPostdecl = "";
    std::string fieldSerializerTemplate = "serialize_normal_field.t";


    //NOTE: shared pointers are easy to copy
    if(fs.flags & FieldFlags::F_VECTOR && fs.flags & FieldFlags::F_POINTER) {
        typeDecl = "std::vector<std::shared_ptr<" + realType + ">>";
        typeSetPredecl = "const";
        typeSetPostdecl = "&";
        fieldSerializerTemplate = "serialize_ref_vector.t";
        if(fs.type == "string") {
            fieldSerializerTemplate = "serialize_ref_vector_string.t";
        } else if(fs.type == "bool") {
            fieldSerializerTemplate = "serialize_ref_vector_bool.t";
        }
    } else if(fs.flags & FieldFlags::F_POINTER) {
        typeDecl = "std::shared_ptr<" + realType + "> ";
        fieldSerializerTemplate = "serialize_sptr_normal_field.t";
        if(fs.type == "string") {
            fieldSerializerTemplate = "serialize_sptr_string.t";
        } else if(fs.type == "bool") {
            fieldSerializerTemplate = "serialize_sptr_bool.t";
        }
    } else if(fs.flags & FieldFlags::F_VECTOR) {
        typeDecl = "std::vector<" + realType + "> ";
        typeSetPredecl = "const";
        typeSetPostdecl = "&";
        if(fs.type == "bool") {
            fieldSerializerTemplate = "serialize_vector_bool.t";
        } else if(fs.type == "string") {
            fieldSerializerTemplate = "serialize_vector_string.t";
        } else {
            fieldSerializerTemplate = "serialize_vector.t";
        }
    } else {
        if(isOutputTemplateRegistered(realType)) {
            t.addDependent(realType);
            typeSetPredecl = "const";
            typeSetPostdecl = "&";
            fieldSerializerTemplate = "serialize_normal_field.t"; //superfluous
        } else if(fs.type == "string") {
            typeSetPredecl = "const";
            typeSetPostdecl = "&";
            fieldSerializerTemplate = "serialize_string.t";
        } else if(fs.type == "bool") {
            fieldSerializerTemplate = "serialize_bool.t";
        }
    }
    //1:: insert declaration
    t.insertBeforeMarker("field_decl_end", typeDecl + " " + varName + ";");
    //2:: reference getter
    FTemplate refGetterTemplate("", getTemplateContent("ref_getter_content.t"));
    refGetterTemplate.replaceToken("type", typeDecl);
    refGetterTemplate.replaceToken("field_name", fs.name);
    refGetterTemplate.replaceToken("var_name", varName);
    t.insertBeforeMarker("ref_getters_end", refGetterTemplate.getContent());

    //3:: standard getter and setter
    FTemplate stdGetterTemplate("", getTemplateContent("std_getter_content.t"));
    stdGetterTemplate.replaceToken("type", typeDecl);
    stdGetterTemplate.replaceToken("field_name", fs.name);
    stdGetterTemplate.replaceToken("var_name", varName);
    stdGetterTemplate.replaceToken("type_pre_modifier", typeSetPredecl);
    stdGetterTemplate.replaceToken("type_post_modifier", typeSetPostdecl);
    t.insertBeforeMarker("getters_end", stdGetterTemplate.getContent());

    //4::serializers
    if(ndx > 0) {
        t.insertBeforeMarker("field_ostream_end", "__stream << \",\";");
    }
    FTemplate stdSerializer("", getTemplateContent(fieldSerializerTemplate));
    stdSerializer.replaceToken("type", typeDecl);
    stdSerializer.replaceToken("field_name", fs.name);
    stdSerializer.replaceToken("var_name", varName);
    t.insertBeforeMarker("field_ostream_end", stdSerializer.getContent());

    //5::deserializers
//    if(ndx > 0) {
//        t.insertBeforeMarker("field_istream_end", "else");
//    }
//    std::string fieldDeserializerTemplate = "de" + fieldSerializerTemplate;
//    FTemplate stdDeserializer("", getTemplateContent(fieldDeserializerTemplate));
//    stdDeserializer.replaceToken("type", typeDecl);
//    stdDeserializer.replaceToken("field_name", fs.name);
//    stdDeserializer.replaceToken("var_name", varName);
//    t.insertBeforeMarker("field_ostream_end", stdDeserializer.getContent());

    return true;
}

bool JsonGenerator::createImportList(FTemplate & t, BeanClazzSpecification & bcs) {
    return true;
}

bool JsonGenerator::createFullFieldConstructor(FTemplate & t, BeanClazzSpecification & bcs) {
    return true;
}

bool JsonGenerator::registerOutputTemplate(const std::string & name, const std::string & content) {
    if(outputTemplates.find(name) != outputTemplates.end()) {
        std::ostringstream msg;
        msg << "Duplicate bean found :" << name;
        addError(msg.str());
        return false;
    }
    outputTemplates.insert(std::make_pair(name, FTemplate(name, content)));
    return true;
}

bool JsonGenerator::isOutputTemplateRegistered(const std::string & name) {
    return (outputTemplates.find(name) != outputTemplates.end());
}

FTemplate & JsonGenerator::getTemplate(const std::string & beanName) {
    std::map<std::string, FTemplate>::iterator i = outputTemplates.find(beanName);
    if(i == outputTemplates.end()) {
        throw std::runtime_error("Non-existent template ?!? Hell.");
    }
    return i->second;
}

//virtual
bool JsonGenerator::createOutput() {
    //let's not forget about json_utils.hpp
    std::string content = getTemplateContent("json_utils.hpp");
    registerOutputTemplate("json_utils", content);

    std::map<std::string, FTemplate>::iterator i = outputTemplates.begin();
    for(; i != outputTemplates.end(); ++i) {
        std::string fName = i->first + ".hpp";
        writeContent(fName, i->second.getContent());
    }
    return true;
}

}
