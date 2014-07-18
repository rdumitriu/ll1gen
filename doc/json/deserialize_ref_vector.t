    
    if(__propertyName == "$field_name$") {
        ll1gen::json::lookUpAndEat(__stream, "[");
        while(1) {
            std::shared_ptr<$type$> __item = std::make_shared<$type>();
            if(!ll1gen::json::lookUpNull(__stream)) {
                __stream >> *__item;
            } else {
               __item.reset(); 
            }
            __bean.$var_name$.push_back(std::move(__item));
            char nextChar = ll1gen::json::lookUpAndEat(__stream, ",]");
            if(nextChar == ']') { break; }
        }
    }
