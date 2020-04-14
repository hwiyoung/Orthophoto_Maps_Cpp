cmake_minimum_required(VERSION 3.10)
project(Orthophoto_Maps_Cpp)

set(CMAKE_CXX_STANDARD 14)

find_package(exiv2lib REQUIRED CONFIG NAMES exiv2)
find_package(OpenCV REQUIRED)
# find system installed GDAL package with predefined CMake variable for finding GDAL
find_package(GDAL REQUIRED)

# Specify location of GDAL header files
include_directories(include ${GDAL_INCLUDE_DIRS})

link_libraries(exiv2lib ${OpenCV_LIBS} ${GDAL_LIBRARIES})

add_executable(Orthophoto_Maps_Cpp main.cpp)
add_executable(exifprint samples/exifprint.cpp)
add_executable(xmpprint samples/xmpprint.cpp)
add_executable(metadataparsing metadataparsing.cpp)
add_executable(SURF_FLANN_matching_homography_Demo samples/SURF_FLANN_matching_homography_Demo.cpp)
add_executable(raster_api samples/raster_api.cpp)