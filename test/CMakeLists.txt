## include the following if you want to use ctest to find & run all the test
# include(GoogleTest)
include(CTest)
enable_testing()

add_executable(ExampleFunc_test ExampleFunc_test.cpp)
target_link_libraries(ExampleFunc_test PRIVATE ${CONAN_LIBS} ExampleFunc)

add_test(
    NAME ExampleFunc_test
    COMMAND ExampleFunc_test
)