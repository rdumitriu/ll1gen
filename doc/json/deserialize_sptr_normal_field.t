    if(__propertyName == "$field_name$") {
        __bean.$var_name$ = std::make_shared<$type$>();
        if(!ll1gen::json::lookUpNull(__stream)) {
            __stream >> *(__bean.$var_name$);
        } else {
            __bean.$var_name$.reset();
        }
    }
