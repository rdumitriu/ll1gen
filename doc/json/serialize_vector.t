    __stream << "[";
    for(unsigned int __index = 0; __index < __bean.$var_name$.size(); ++__index) {
        auto & __item = __bean.$var_name$.at(__index);
        __stream << __item;
        if(__index != __bean.$var_name$.size() - 1) {
            __stream << ",";
        }
    }
    __stream << "]";

