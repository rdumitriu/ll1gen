    if(__propertyName == "$field_name$") {
        if(!ll1gen::json::lookUpNull(__stream)) {
            __bean.$var_name$ = std::make_shared<bool>();
            ll1gen::json::parseBool(__stream, *(__bean.$var_name$));
        } else {
            __bean.$var_name$.reset();
        }
    }
