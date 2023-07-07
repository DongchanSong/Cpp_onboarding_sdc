add_test( M300_GPS.m300_GPS [==[/home/dongchansong/C_C++_Projects/build/myTest]==] [==[--gtest_filter=M300_GPS.m300_GPS]==] --gtest_also_run_disabled_tests)
set_tests_properties( M300_GPS.m300_GPS PROPERTIES WORKING_DIRECTORY [==[/home/dongchansong/C_C++_Projects/build]==])
add_test( M600_GPS.m600_GPS [==[/home/dongchansong/C_C++_Projects/build/myTest]==] [==[--gtest_filter=M600_GPS.m600_GPS]==] --gtest_also_run_disabled_tests)
set_tests_properties( M600_GPS.m600_GPS PROPERTIES WORKING_DIRECTORY [==[/home/dongchansong/C_C++_Projects/build]==])
add_test( Mavic_GPS.mavic_GPS [==[/home/dongchansong/C_C++_Projects/build/myTest]==] [==[--gtest_filter=Mavic_GPS.mavic_GPS]==] --gtest_also_run_disabled_tests)
set_tests_properties( Mavic_GPS.mavic_GPS PROPERTIES WORKING_DIRECTORY [==[/home/dongchansong/C_C++_Projects/build]==])
add_test( Skydio_GPS.skydio_GPS [==[/home/dongchansong/C_C++_Projects/build/myTest]==] [==[--gtest_filter=Skydio_GPS.skydio_GPS]==] --gtest_also_run_disabled_tests)
set_tests_properties( Skydio_GPS.skydio_GPS PROPERTIES WORKING_DIRECTORY [==[/home/dongchansong/C_C++_Projects/build]==])
set( myTest_TESTS M300_GPS.m300_GPS M600_GPS.m600_GPS Mavic_GPS.mavic_GPS Skydio_GPS.skydio_GPS)
