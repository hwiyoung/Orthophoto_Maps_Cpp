cmake_minimum_required(VERSION 3.10)
project(Orthophoto_Maps_Cpp)

set(CMAKE_CXX_STANDARD 14)

find_package(exiv2lib REQUIRED CONFIG NAMES exiv2)
find_package(OpenCV REQUIRED)

link_libraries(exiv2lib ${OpenCV_LIBS})

add_executable(Orthophoto_Maps_Cpp main.cpp)
add_executable(exifprint samples/exifprint.cpp)
add_executable(xmpprint samples/xmpprint.cpp)
add_executable(metadataparsing metadataparsing.cpp)
add_executable(SURF_FLANN_matching_homography_Demo samples/SURF_FLANN_matching_homography_Demo.cpp)