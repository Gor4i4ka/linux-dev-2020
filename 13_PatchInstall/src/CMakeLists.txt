add_executable(task9 task9.c)
#add_definitions(-DLOCALE_PATH="${PROJECT_BINARY_DIR}/bin")
#include(GNUInstallDirs)
#add_definitions(-DLOCALE_PATH="/usr/${CMAKE_INSTALL_LOCALEDIR}")
add_definitions(-DLOCALE_PATH="${LOCALE_PATH}")
install(TARGETS task9 DESTINATION bin)
