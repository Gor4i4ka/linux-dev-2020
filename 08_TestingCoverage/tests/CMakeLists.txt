find_package (Boost COMPONENTS unit_test_framework REQUIRED)


add_executable(test1 test1.c)
add_executable(test2 test2.c)
add_executable(test3 test3.c)
target_link_libraries(test1 ${Boost_LIBRARIES} buf)
target_link_libraries(test2 ${Boost_LIBRARIES} buf)
target_link_libraries(test3 ${Boost_LIBRARIES} buf)
add_test(NAME Test1 COMMAND test1)
add_test(NAME Test2 COMMAND test2)
add_test(NAME Test3 COMMAND test3)
