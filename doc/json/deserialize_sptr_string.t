    if(__propertyName == "$field_name$") {
        if(!ll1gen::json::lookupNull(__stream)) {
            __bean.$var_name$ = std::make_shared<std::string>();
            ll1gen::json::parseString(__stream, *(__bean.$var_name$));
        }
    }
