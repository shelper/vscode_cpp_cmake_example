cmake_minimum_required(VERSION 3.0.0)
project(Example VERSION 0.1.0)

## try not set custom variables
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

## include the following if you want to use ctest to find & run all the test
# include(CTest)
# include(GoogleTest)
# enable_testing()

add_library(ExampleFunc ExampleFunc.cpp)
add_executable(main main.cpp)
add_subdirectory(test)

target_compile_features(main PUBLIC cxx_std_17)

find_package(OpenCV CONFIG REQUIRED) 
target_include_directories(main PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(main ${OpenCV_LIBRARIES})

## for packing the binary/source for installation
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
