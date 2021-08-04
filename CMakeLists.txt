# CMakeList.txt : CMake project for 3Rmanipulator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("3Rmanipulator" VERSION 1.0.0)

add_subdirectory(3Rmanipulator)


# Add source to this project's executable.
add_executable (test_project "test_lib.cpp")

target_link_libraries(test_project PRIVATE 3Rmanipulator)

# TODO: Add tests and install targets if needed.
