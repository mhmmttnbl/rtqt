add_library(dataframe STATIC "dataframe.cc")

target_include_directories(dataframe PUBLIC "${CMAKE_SOURCE_DIR}"
                                            "${CMAKE_CURRENT_SOURCE_DIR}")