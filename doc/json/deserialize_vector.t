    
    if(__propertyName == "$field_name$") {
        __bean.$var_name$.clear();
        ll1gen::json::lookUpAndEat(__stream, "[");
        if(!ll1gen::json::lookUpEmptyArray(__stream)) {
        while(1) {
            $item_type$ __item;
            if(!ll1gen::json::lookUpNull(__stream)) {
                __stream >> __item;
            } else {
                throw std::runtime_error("JSON: null not supported for field $field_name$ (vector). Check definition");
            }
            __bean.$var_name$.push_back(std::move(__item));
            char nextChar = ll1gen::json::lookUpAndEat(__stream, ",]");
            if(nextChar == ']') { break; }
        }
        }
    }
