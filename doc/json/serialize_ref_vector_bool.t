    __stream << "[";
    for(unsigned int __index = 0; __index < __bean.$var_name$.size() - 1; ++__index) {
        auto & __item = __bean.$var_name$.at(__index);
        if(__item.get()) {
            __stream << *__item ? "true" : "false";
        } else {
            __stream << "null";
        }
        __stream << ",";
    }
    if(__bean.$var_name$.size()) {
        auto & __item = __bean.$var_name$.at(__bean.$var_name$.size() - 1);
        if(__item.get()) {
            __stream << *__item ? "true" : "false";
        } else {
            __stream << "null";
        }
    }
    __stream << "]";

