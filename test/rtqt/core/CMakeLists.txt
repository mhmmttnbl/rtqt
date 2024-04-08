include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${CMAKE_BINARY_DIR}/_deps/googletest-src/googlemock/include")
include_directories("${CMAKE_BINARY_DIR}/_deps/googletest-src/googletest/include")

add_executable(test_core_pair       "test_core_pair.cc")
add_executable(test_core_functional "test_core_functional.cc")

target_link_directories(test_core_pair       PRIVATE "${CMAKE_BINARY_DIR}/rtqt/core")
target_link_directories(test_core_functional PRIVATE "${CMAKE_BINARY_DIR}/rtqt/core")

target_link_libraries(test_core_pair       gtest gmock core)
target_link_libraries(test_core_functional gtest gmock core)