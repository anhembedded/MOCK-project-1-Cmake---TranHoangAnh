# CMakeList.txt : CMake project for MOCK project 1 Cmake - TranHoangAnh, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (CMakeTarget "MOCK project 1 Cmake - TranHoangAnh.c" "MOCK project 1 Cmake - TranHoangAnh.h" u_dataType/U_2dBinaryMatrix.c u_dataType/U_2dBinaryMatrix.h u_theRottenApple.c u_theRottenApple.h "u_dataType/U_staticMethod_2dBinaryMatrix.h")
include_directories(${MY_CURRENT_DIR}/)
include_directories(${YOUR_DIRECTORY})
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY C_STANDARD 11)
endif()

# TODO: Add tests and install targets if needed.
