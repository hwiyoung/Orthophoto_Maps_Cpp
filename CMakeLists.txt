cmake_minimum_required(VERSION 3.10)
project(Orthophoto_Maps_Cpp)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
find_package(exiv2 REQUIRED CONFIG NAMES exiv2)    # search ${CMAKE_INSTALL_PREFIX}/lib/cmake/exiv2
find_package(GDAL REQUIRED)     # find system installed GDAL package with predefined CMake variable for finding GDAL

add_executable(Orthophoto_Maps_Cpp main.cpp)

include_directories(include ${GDAL_INCLUDE_DIRS})  # Specify location of GDAL header files

target_link_libraries(Orthophoto_Maps_Cpp ${OpenCV_LIBS})
target_link_libraries(Orthophoto_Maps_Cpp exiv2)             # link exiv2
target_link_libraries(Orthophoto_Maps_Cpp ${GDAL_LIBRARIES})  # Specify GDAL libraries to link your cpp executable target against