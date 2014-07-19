    __stream << "\"$field_name$\":[";
    if(!__bean.$var_name$.empty()) {
        for(unsigned int __index = 0; __index < __bean.$var_name$.size() - 1; ++__index) {
            auto & __item = __bean.$var_name$.at(__index);
            __stream << "\"" << ll1gen::json::encodeJsonString(__item) << "\"";
            __stream << ",";
        }
        __stream << "\"" << ll1gen::json::encodeJsonString(__bean.$var_name$.at(__bean.$var_name$.size() - 1)) << "\"";
    }
    __stream << "]";
