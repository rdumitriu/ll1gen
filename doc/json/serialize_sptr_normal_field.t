    if(__bean.$var_name$.get()) {
        __stream << "\"$field_name$\":" << *__bean.$var_name$;
    } else {
        __stream << "\"$field_name$\": null";
    }

