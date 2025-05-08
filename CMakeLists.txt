cmake_minimum_required(VERSION 3.10.0)
project(jf_lib VERSION 0.1.0 LANGUAGES C)

add_library(jf_lib src/jf_ds/jf_linked_list.h)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
