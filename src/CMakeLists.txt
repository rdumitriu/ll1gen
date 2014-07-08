
PROJECT (ll1gen)


SET (ll1gen_SRC
    ../include/specification.hpp

    ../include/spec_parser.hpp
    spec_parser.cpp

    ../include/ftemplate.hpp
    ftemplate.cpp

    ../include/json_utils.hpp

    ../include/generator.hpp
    generator.cpp

    ../include/json_generator.hpp
    json_generator.cpp

    main.cpp
     )

ADD_EXECUTABLE(ll1gen ${ll1gen_SRC})

INCLUDE_DIRECTORIES ("../include")

TARGET_LINK_LIBRARIES(ll1gen ${LIBS})

INSTALL(TARGETS ll1gen DESTINATION "${LL1GEN_INSTALL_BIN}")

