cmake_minimum_required(VERSION 3.0.0)
project(Example VERSION 0.1.0)

## try not set custom variables
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

## include the following if you want to use ctest to find & run all the test
# include(GoogleTest)
include(CTest)
enable_testing()

## setup conan libraries
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

## add target after setting up conan
add_library(ExampleFunc ExampleFunc.cpp)
add_executable(main main.cpp) # put this after conan_basic_setup().
set_target_properties( main ExampleFunc
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

## set the linkage using conan
target_link_libraries(main PRIVATE ${CONAN_LIBS})
## enable c++17
target_compile_features(main PUBLIC cxx_std_17)

## add additional folder that contains CMakeLists.txt
add_subdirectory(test)

## for packing the binary/source for installation
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
