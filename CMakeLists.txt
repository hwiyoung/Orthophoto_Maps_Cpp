cmake_minimum_required(VERSION 3.10)
project(Orthophoto_Maps_Cpp)

set(CMAKE_CXX_STANDARD 14)

find_package(exiv2lib REQUIRED CONFIG NAMES exiv2)

link_libraries(exiv2lib)

add_executable(Orthophoto_Maps_Cpp main.cpp)
add_executable(exifprint samples/exifprint.cpp)
add_executable(xmpprint samples/xmpprint.cpp)
add_executable(metadataparsing metadataparsing.cpp)