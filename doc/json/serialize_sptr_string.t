    if(__bean.$var_name$.get()) {
        __stream << "\"$field_name$\":" << "\"" << ll1gen::json::encodeJsonString(*__bean.$var_name$) << "\"";
    } else {
        __stream << "\"$field_name$\": null";
    }
