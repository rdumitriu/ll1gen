    if(__propertyName == "$field_name$") {
        if(!ll1gen::json::lookUpNull(__stream)) {
            __stream >> __bean.$var_name$;
        } else {
            throw std::runtime_error("JSON: null not supported for field $field_name$. Check definition");
        }
    }
