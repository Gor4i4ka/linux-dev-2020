cmake_minimum_required(VERSION 2.6)
project(task9)

SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/bin
        CACHE PATH
        "Single Directory for all"
    )
SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY
	${PROJECT_BINARY_DIR}/bin/fr/LC_MESSAGES
        CACHE PATH
        "Single Directory for all"
    )

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/bin/ru/LC_MESSAGES)
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/bin/en/LC_MESSAGES)
add_subdirectory(po po)
add_subdirectory(src src)

add_custom_command(
	OUTPUT update
	COMMAND xgettext --keyword=_ --language=C --add-comments --sort-output -o ${PROJECT_SOURCE_DIR}/po/task9.pot ${PROJECT_SOURCE_DIR}/src/task9.c
	COMMAND msgmerge --update ${PROJECT_SOURCE_DIR}/po/ru/task9.po ${PROJECT_SOURCE_DIR}/po/task9.pot
	COMMAND msgmerge --update ${PROJECT_SOURCE_DIR}/po/en/task9.po ${PROJECT_SOURCE_DIR}/po/task9.pot
	)
add_custom_target(
	update_po
	DEPENDS update)
add_custom_target(allclean COMMAND rm -r ${PROJECT_BINARY_DIR}/*)

