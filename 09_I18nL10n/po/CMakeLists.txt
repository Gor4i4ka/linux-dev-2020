set(path ${PROJECT_BINARY_DIR}/bin/ru/LC_MESSAGES)
execute_process(COMMAND msgfmt --output-file=${path}/task9.mo ${PROJECT_SOURCE_DIR}/po/ru/task9.po)
