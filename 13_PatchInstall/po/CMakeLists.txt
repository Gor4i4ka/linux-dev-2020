set(path ${PROJECT_BINARY_DIR}/bin/ru/LC_MESSAGES)
add_custom_target(
	produce_mo
	ALL
	COMMAND msgfmt --output-file=${path}/task9.mo ${PROJECT_SOURCE_DIR}/po/ru/task9.po
	BYPRODUCTS task9.mo)
include(GNUInstallDirs)
install(FILES ${path}/task9.mo DESTINATION /usr/share/locale/ru/LC_MESSAGES)
