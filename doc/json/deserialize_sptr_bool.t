    if(__propertyName == "$field_name$") {
        __bean.$var_name$ = std::make_shared<bool>();
        if(!ll1gen::json::detail::lookUpNull(__stream)) {
            ll1gen::json::detail::parseBool(__stream, *(__bean.$var_name$));
        } else {
            __bean.$var_name$.reset();
        }
    }
