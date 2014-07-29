    if(__propertyName == "$field_name$") {
        __bean.$var_name$ = std::make_shared<$item_type$>();
        if(!ll1gen::json::detail::lookUpNull(__stream)) {
            __stream >> *(__bean.$var_name$);
        } else {
            __bean.$var_name$.reset();
        }
    }
