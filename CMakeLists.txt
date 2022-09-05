# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("MOCK project 1 Cmake - TranHoangAnh")

# Include sub-projects.
add_subdirectory ("MOCK project 1 Cmake - TranHoangAnh")
include_directories(${MY_CURRENT_DIR}/)
