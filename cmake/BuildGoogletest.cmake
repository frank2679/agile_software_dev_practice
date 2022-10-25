# Copyright 2022, Biren Technologies Inc.
# All rights reserved.

if(template_build_googletest_cmake_included)
    return()
endif()
set(template_build_googletest_cmake_included true)

if(TEMPLATE_BUILD_TESTS)
    if(NOT TARGET gtest)
        message(STATUS "Project is configured to build tests")
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
        set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
        add_subdirectory(3rdparty/googletest)

        # Set googletest libraries to tmp_gtest and tmp_gtest_main to avoid
        # dependency conflicts
        set_target_properties(gtest PROPERTIES PREFIX "tmp_"
            POSITION_INDEPENDENT_CODE ON)
        set_target_properties(gtest_main PROPERTIES PREFIX "tmp_"
            POSITION_INDEPENDENT_CODE ON)
    endif()
endif()
