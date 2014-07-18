    if(__propertyName == "$field_name$") {
        if(!ll1gen::json::parseString(__stream, __bean.$var_name$)) {
            throw new std::runtime_error("JSON: null not supported for field $field_name$ (string). Check definition.");
        }
    }
