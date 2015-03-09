CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

enable_testing ()

PROJECT (ll1gen)

SET(CMAKE_INSTALL_PREFIX "ll1gen-home")

SET(LL1GEN_INSTALL_BIN "bin")
SET(LL1GEN_INSTALL_TMPL "templates")
SET(LL1GEN_INSTALL_TMPL_JSON "${LL1GEN_INSTALL_TMPL}/json")

#
# Setting the global stuff
#

#-Weffc++
SET( AGRADE_GLOBAL_CXX_FLAGS "-Wall -Wold-style-cast -Woverloaded-virtual -Wl,-E -std=c++0x" )
SET(LL1GEN_DEBUG "true")

IF(UNIX)
  SET(LIBS "-ldl -lpthread")
  IF(CMAKE_SIZEOF_VOID_P EQUAL 8)
    LINK_DIRECTORIES("/usr/lib64"
                     "/usr/local/lib64")
    SET( AGRADE_GLOBAL_CXX_FLAGS "${AGRADE_GLOBAL_CXX_FLAGS} -m64 -fPIC")
  ELSE()
    LINK_DIRECTORIES("/usr/lib"
                     "/usr/local/lib")
    SET( AGRADE_GLOBAL_CXX_FLAGS "${AGRADE_GLOBAL_CXX_FLAGS} -m32 -fPIC")
  ENDIF()
ELSE(NOT UNIX)
  message(FATAL_ERROR " I was only tested on LINUX. You really need to work to build me.")
ENDIF(UNIX)

#
# BOOST SUPPORT
#

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED     OFF)
set(Boost_USE_STATIC_RUNTIME    OFF)

FIND_PACKAGE(Boost REQUIRED COMPONENTS program_options system filesystem)

IF(DEFINED LL1GEN_DEBUG)
  ADD_DEFINITIONS(-D_DEBUG)
  message ("Debug version, please undefine LL1GEN_DEBUG if you want the release version")
  SET( CMAKE_CXX_FLAGS "${AGRADE_GLOBAL_CXX_FLAGS} -g -O0")
ELSE (NOT DEFINED LL1GEN_DEBUG)
  SET( CMAKE_CXX_FLAGS "${AGRADE_GLOBAL_CXX_FLAGS} -O3")
ENDIF(DEFINED LL1GEN_DEBUG)

INCLUDE_DIRECTORIES ("${Boost_INCLUDE_DIR}")

SET(LIBS ${LIBS} ${Boost_LIBRARIES})

ADD_SUBDIRECTORY ("src")
ADD_SUBDIRECTORY ("test")

INSTALL(DIRECTORY DESTINATION ${LL1GEN_INSTALL_BIN})
INSTALL(DIRECTORY DESTINATION ${LL1GEN_INSTALL_TMPL})
INSTALL(DIRECTORY DESTINATION ${LL1GEN_INSTALL_TMPL_JSON})

INSTALL(FILES ${CMAKE_SOURCE_DIR}/include/json_utils.hpp
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/json_bean_template.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
#INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/ref_getter_content.t
#        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/std_getter_content.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/std_constructor_param.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/std_constructor_assign.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/std_copyconstructor_assign.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/std_opeq_assign.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")

INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/serialize_bool.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/deserialize_bool.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")


INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/serialize_normal_field.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/deserialize_normal_field.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")

INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/serialize_string.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/deserialize_string.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")


INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/serialize_ref_vector_bool.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/deserialize_ref_vector_bool.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")

INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/serialize_ref_vector_string.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/deserialize_ref_vector_string.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")

INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/serialize_ref_vector.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/deserialize_ref_vector.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")

INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/serialize_sptr_bool.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/deserialize_sptr_bool.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")

INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/serialize_sptr_normal_field.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/deserialize_sptr_normal_field.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")

INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/serialize_sptr_string.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/deserialize_sptr_string.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")

INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/serialize_vector_bool.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/deserialize_vector_bool.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")

INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/serialize_vector_string.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/deserialize_vector_string.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")

INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/serialize_vector.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
INSTALL(FILES ${CMAKE_SOURCE_DIR}/doc/json/deserialize_vector.t
        DESTINATION "${LL1GEN_INSTALL_TMPL_JSON}")
