    if(__propertyName == "$field_name$") {
        if(!ll1gen::json::lookUpNull(__stream)) {
            __bean.$var_name$ = std::make_shared<std::string>();
            ll1gen::json::parseString(__stream, *(__bean.$var_name$));
        } else {
            __bean.$var_name$.reset();
        }
    }
