cmake_minimum_required(VERSION 3.18.0)
project(001_hello VERSION 0.1.0)

include(CTest)
enable_testing()

option(TEMPLATE_BUILD_TESTS "Build all tests." ON)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include("cmake/BuildGoogletest.cmake")


add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
