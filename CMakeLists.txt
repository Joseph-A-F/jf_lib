cmake_minimum_required(VERSION 3.10.0)
project(jf_lib VERSION 0.1.0 LANGUAGES C)

add_library(jf_lib src/jf_linked_list.h
        src/jf_linked_list.c
        src/jf_string.h
        src/jf_string.c
        src/jf_file.h
        src/jf_file.c)
target_include_directories(jf_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# include(CTest)
# enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
