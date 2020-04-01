cmake_minimum_required(VERSION 3.0.0)
project(Example VERSION 0.1.0)

include(CTest)
include(GoogleTest)
enable_testing()
add_subdirectory(test)

add_executable(main main.cpp)

find_package(OpenCV REQUIRED) 
target_include_directories(main PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(main ${OpenCV_LIBRARIES})

add_library(ExampleFunc ExampleFunc.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
