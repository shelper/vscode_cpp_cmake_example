cmake_minimum_required(VERSION 3.0.0)
project(Example VERSION 0.1.0)
# add_compile_options(-std=c++11) # this is for global c++11 settings, below we already set target_compile_features()

if(EXISTS "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
    message("Using toolchain file from CONAN")
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup() # conan sets up everything for you, only for CMAKE > 3.1.2, with this you can use CONAN_LIBS below
    # conan_basic_setup(TARGETS) # conan sets up CMAKE variables by targets, with this you can use CONAN_PKG:: below
else()
    message("Using toolchain file from VCPKG to mock CONAN")
    include($ENV{vcpkgRoot}/scripts/buildsystems/vcpkg.cmake) # vcpkg needs to add libs one by one
    find_package(OpenCV CONFIG REQUIRED) 
    find_package(GTest CONFIG REQUIRED)
    set(CONAN_LIBS GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main ${OpenCV_LIBRARIES} )
endif()

# add and setup targets in the folder
add_library(ExampleFunc ExampleFunc.cpp)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE ${CONAN_LIBS})
# target_link_libraries(main PRIVATE CONAN_PKG::gtest CONAN_PKG::opencv)

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
