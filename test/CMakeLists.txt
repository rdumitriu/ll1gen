CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

enable_testing ()

SET (MLIB ${LIBS})

ADD_DEFINITIONS(-D_DEBUG)

# LOG TESTS

ADD_EXECUTABLE(testspecp ../src/spec_parser.cpp test_spec_parser.cpp)
INCLUDE_DIRECTORIES ("../include")
TARGET_LINK_LIBRARIES (testspecp  ${MLIB})

ADD_EXECUTABLE(test_template _template.hpp test_template.cpp)
INCLUDE_DIRECTORIES ("../include")
TARGET_LINK_LIBRARIES (test_template  ${MLIB})

ADD_EXECUTABLE(test_HelloBean hellobean.hpp test_HelloBean.cpp)
INCLUDE_DIRECTORIES ("../include")
TARGET_LINK_LIBRARIES (test_HelloBean  ${MLIB})


ADD_TEST(testspecp1 testspecp ${CMAKE_CURRENT_SOURCE_DIR}/good.desc)
SET_TESTS_PROPERTIES (testspecp1
                      PROPERTIES
                      FAIL_REGULAR_EXPRESSION "FAILED.*")

