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

add_subdirectory(test)
add_executable(main main.cpp)

find_package(OpenCV REQUIRED) 
target_compile_features(main PUBLIC cxx_std_17)
target_include_directories(main PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(main ${OpenCV_LIBRARIES})

add_library(ExampleFunc ExampleFunc.cpp)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)