cmake_minimum_required(VERSION 3.16)

project(rtqt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(DependGoogleTest)

add_subdirectory(rtqt)
add_subdirectory(test)