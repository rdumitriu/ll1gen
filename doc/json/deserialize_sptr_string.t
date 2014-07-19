    if(__propertyName == "$field_name$") {
        __bean.$var_name$ = std::make_shared<std::string>();
        if(!ll1gen::json::lookUpNull(__stream)) {
            ll1gen::json::parseString(__stream, *(__bean.$var_name$));
        } else {
            __bean.$var_name$.reset();
        }
    }
