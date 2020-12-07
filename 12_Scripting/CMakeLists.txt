cmake_minimum_required(VERSION 3.10)
project(task8)
set (version 0.12)



set (CMAKE_LIBRARY_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/bin
        CACHE PATH
        "Single Directory for all"
    )

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/bin
        CACHE PATH
        "Single Directory for all"
    )

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY
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

add_custom_target(comment_addition ALL)

set(path_src ${PROJECT_SOURCE_DIR}/src)
set(path_include ${PROJECT_SOURCE_DIR}/include)
set(path_script ${PROJECT_SOURCE_DIR}/scripts)

execute_process(
	COMMAND bash ${path_script}/comment_script.sh ${path_src} ${PROJECT_NAME} ${version}
	COMMAND bash ${path_script}/comment_script.sh ${path_include} ${PROJECT_NAME} ${version}
	)

#add_custom_command(
#        TARGET comment_addition
#        PRE_BUILD
#	COMMAND ${path_script}/comment_script.sh
#        )
#COMMAND ${path_script}/comment_script.sh ${path_src} ${PROJECT_NAME} ${version}
#COMMAND ${path_script}/comment_script.sh ${path_include} ${PROJECT_NAME} ${version}

