cmake_minimum_required(VERSION 3.18.0)
project(001_hello VERSION 0.1.0)

include(CTest)
enable_testing()

option(TEMPLATE_BUILD_TESTS "Build all tests." ON)
option(DEFAULT_DEBUG_BUILD_TYPE "Default debug build" OFF)

if(DEFAULT_DEBUG_BUILD_TYPE)
  message(STATUS "Debug build")
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
else()
  message(STATUS "Release build")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include("cmake/BuildGoogletest.cmake")


add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
