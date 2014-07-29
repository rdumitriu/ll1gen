CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

enable_testing ()

SET (MLIB ${LIBS})

ADD_DEFINITIONS(-D_DEBUG)

# LOG TESTS

ADD_EXECUTABLE(testspecp ../src/spec_parser.cpp test_spec_parser.cpp)
INCLUDE_DIRECTORIES ("../include")
TARGET_LINK_LIBRARIES (testspecp  ${MLIB})

ADD_EXECUTABLE(test_stdex0 test_stdex0.cpp)
INCLUDE_DIRECTORIES ("../include")
TARGET_LINK_LIBRARIES (test_stdex0  ${MLIB})

ADD_EXECUTABLE(test_stdex1 test_stdex1.cpp)
INCLUDE_DIRECTORIES ("../include")
TARGET_LINK_LIBRARIES (test_stdex1  ${MLIB})

ADD_EXECUTABLE(test_template test_template.cpp)
INCLUDE_DIRECTORIES ("../include")
TARGET_LINK_LIBRARIES (test_template  ${MLIB})

ADD_EXECUTABLE(test_HelloBean test_HelloBean.cpp)
INCLUDE_DIRECTORIES ("../include")
TARGET_LINK_LIBRARIES (test_HelloBean  ${MLIB})

ADD_EXECUTABLE(test_2Simple test_2Simple.cpp)
INCLUDE_DIRECTORIES ("../include")
TARGET_LINK_LIBRARIES (test_2Simple  ${MLIB})

ADD_EXECUTABLE(test_2Multi test_2Multi.cpp)
INCLUDE_DIRECTORIES ("../include")
TARGET_LINK_LIBRARIES (test_2Multi  ${MLIB})

ADD_EXECUTABLE(test_3ArrRef test_3ArrRef.cpp)
INCLUDE_DIRECTORIES ("../include")
TARGET_LINK_LIBRARIES (test_3ArrRef  ${MLIB})


ADD_TEST(test_stdex0t test_stdex0 ${CMAKE_CURRENT_SOURCE_DIR}/)
SET_TESTS_PROPERTIES (test_stdex0t
                      PROPERTIES
                      FAIL_REGULAR_EXPRESSION "FAILED.*")

ADD_TEST(test_stdex1t test_stdex1 ${CMAKE_CURRENT_SOURCE_DIR}/)
SET_TESTS_PROPERTIES (test_stdex1t
                      PROPERTIES
                      FAIL_REGULAR_EXPRESSION "FAILED.*")


ADD_TEST(testspecp1 testspecp ${CMAKE_CURRENT_SOURCE_DIR}/good.desc)
SET_TESTS_PROPERTIES (testspecp1
                      PROPERTIES
                      FAIL_REGULAR_EXPRESSION "FAILED.*")

ADD_TEST(test_HelloBean1 test_HelloBean)
SET_TESTS_PROPERTIES (test_HelloBean1
                      PROPERTIES
                      FAIL_REGULAR_EXPRESSION "FAILED.*")

ADD_TEST(test_2Simple1 test_2Simple)
SET_TESTS_PROPERTIES (test_2Simple1
                      PROPERTIES
                      FAIL_REGULAR_EXPRESSION "FAILED.*")

ADD_TEST(test_2Multi1 test_2Multi)
SET_TESTS_PROPERTIES (test_2Multi1
                      PROPERTIES
                      FAIL_REGULAR_EXPRESSION "FAILED.*")

ADD_TEST(test_3ArrRef1 test_3ArrRef)
SET_TESTS_PROPERTIES (test_3ArrRef1
                      PROPERTIES
                      FAIL_REGULAR_EXPRESSION "FAILED.*")

