cmake_minimum_required(VERSION 2.6)
project(task8)

SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/bin
        CACHE PATH
        "Single Directory for all"
    )

SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/bin
        CACHE PATH
        "Single Directory for all"
    )

SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/lib
        CACHE PATH
        "Single Directory for all"
    )

enable_testing()

find_package(Boost REQUIRED)

include_directories(include)

add_subdirectory( src build/src )
add_subdirectory( tests build/tests )

add_custom_target(allclean COMMAND rm -r ${PROJECT_BINARY_DIR}/*)
