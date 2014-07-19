    
    if(__propertyName == "$field_name$") {
        __bean.$var_name$.clear();
        ll1gen::json::lookUpAndEat(__stream, "[");
        if(!ll1gen::json::lookUpEmptyArray(__stream)) {
        while(1) {
            bool __item;
            if(!ll1gen::json::parseBool(__stream, __item)) {
                throw std::runtime_error("JSON: null is not supported for $field_name$ (vector/bool). Check definition.");
            }
            __bean.$var_name$.push_back(__item);
            char nextChar = ll1gen::json::lookUpAndEat(__stream, ",]");
            if(nextChar == ']') { break; }
        }
        }
    }
