file(GLOB_RECURSE DEMO_SRCS ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
set(TESTNAME hello)
add_executable(${TESTNAME} ${DEMO_SRCS})
add_dependencies(${TESTNAME} gtest gtest_main)

target_include_directories(${TESTNAME} PUBLIC 
    ${PROJECT_SOURCE_DIR}/3rdparty/googletest/googletest/include
)

target_link_libraries(${TESTNAME} 
        $<TARGET_FILE:gtest> 
        $<TARGET_FILE:gtest_main>
        pthread # needed by gtest
)

add_custom_command(TARGET ${TESTNAME} 
    COMMAND ${TESTNAME}
    COMMENT "custom execute the demo")