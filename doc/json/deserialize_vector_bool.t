    
    if(__propertyName == "$field_name$") {
        ll1gen::json::lookUpAndEat(__stream, "[");
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
