find_package(PkgConfig REQUIRED)
pkg_search_module(GLIB REQUIRED glib-2.0)

include_directories(${GLIB_INCLUDE_DIRS})
link_directories(${GLIB_LIBRARY_DIRS})

add_executable(task11 task11.c)

add_definitions(${GLIB_CFLAGS_OTHER})
#add_definitions(-DPATH_TO_FILE="${PROJECT_SOURCE_DIR}/src/file_to_read.txt")
target_link_libraries(task11 ${GLIB_LIBRARIES})
