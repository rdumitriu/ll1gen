    
    if(__propertyName == "$field_name$") {
        ll1gen::json::lookUpAndEat(__stream, "[");
        while(1) {
            std::string __item;
            if(!ll1gen::json::parseString(__stream, __item)) {
                throw new std::runtime_error("JSON: null not supported for field $field_name$ (vector/string). Check definition.");
            }
            __bean.$var_name$.push_back(std::move(__item));
            char nextChar = ll1gen::json::lookUpAndEat(__stream, ",]");
            if(nextChar == ']') { break; }
        }
    }
