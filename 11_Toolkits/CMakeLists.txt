cmake_minimum_required(VERSION 3.1)
project(task11)

SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/bin
        CACHE PATH
        "Single Directory for all"
    )

add_subdirectory(src src)

add_custom_target(allclean COMMAND rm -r ${PROJECT_BINARY_DIR}/*)
