    
    if(__propertyName == "$field_name$") {
        ll1gen::json::lookUpAndEat(__stream, "[");
        while(1) {
            std::shared_ptr<bool> __item = std::make_shared<bool>();
            if(!ll1gen::json::lookUpNull(__stream)) {
                ll1gen::json::parseBool(__stream, *__item);
            } else {
               __item.reset(); 
            }
            __bean.$var_name$.push_back(__item);
            char nextChar = ll1gen::json::lookUpAndEat(__stream, ",]");
            if(nextChar == ']') { break; }
        }
    }
