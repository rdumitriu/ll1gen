    if(__propertyName == "$field_name$") {
        if(!ll1gen::json::detail::parseBool(__stream, __bean.$var_name$)) {
            throw std::runtime_error("JSON: null is not supported for $field_name$ (bool). Check definition.");
        }
    }
