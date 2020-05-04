cmake_minimum_required(VERSION 3.0.0)
project(Example VERSION 0.1.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup() # this replaces find_package()

# add and setup targets in the folder
add_library(ExampleFunc ExampleFunc.cpp)
add_executable(main main.cpp) 
target_link_libraries(main PRIVATE ${CONAN_LIBS})

# add and setup targets in subfolder
add_subdirectory(test)

# set properties for all targets
target_compile_features(main PUBLIC cxx_std_17)
set_target_properties(main ExampleFunc
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)


## for packing the binary/source for installation
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
