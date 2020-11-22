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
	)
add_custom_target(
	update_po
	DEPENDS update)
add_custom_target(allclean COMMAND rm -r ${PROJECT_BINARY_DIR}/*)

option(BUILD_DOC "Build documentation" ON)

find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${PROJECT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${PROJECT_BINARY_DIR}/Doxyfile)

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

add_custom_target(
	ru_help_intro
	COMMAND cp ${PROJECT_SOURCE_DIR}/lib/help_ru.h ${PROJECT_SOURCE_DIR}/docs/help.h
	)

add_custom_target(
        en_help_intro
	COMMAND cp ${PROJECT_SOURCE_DIR}/lib/help_en.h ${PROJECT_SOURCE_DIR}/docs/help.h
        )

add_custom_target(
	install_man
	COMMAND sudo cp ${PROJECT_BINARY_DIR}/doc_doxygen/man/man3/task9.c.3 /usr/local/man/man3/task9.3
	)

add_custom_target(
	doxygen_view
	COMMAND firefox ${PROJECT_BINARY_DIR}/doc_doxygen/html/index.html
	)
