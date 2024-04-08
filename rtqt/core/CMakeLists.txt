add_library(core STATIC "core.cc")

target_include_directories(core PUBLIC "${CMAKE_SOURCE_DIR}"
                                       "${CMAKE_CURRENT_SOURCE_DIR}")