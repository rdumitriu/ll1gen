    if(__propertyName == "$field_name$") {
        __bean.$var_name$ = std::make_shared<bool>();
        if(!ll1gen::json::lookUpNull(__stream)) {
            ll1gen::json::parseBool(__stream, *(__bean.$var_name$));
        } else {
            __bean.$var_name$.reset();
        }
    }
