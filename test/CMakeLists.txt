cmake_minimum_required(VERSION 3.0.0)

add_executable(ExampleFunc_test ExampleFunc_test.cpp)

find_package(GTest CONFIG REQUIRED)
target_compile_features(ExampleFunc_test PUBLIC cxx_std_17)
target_include_directories(ExampleFunc_test PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(ExampleFunc_test PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main ExampleFunc)


add_test(
    NAME ExampleFunc_test
    COMMAND ExampleFunc_test
)