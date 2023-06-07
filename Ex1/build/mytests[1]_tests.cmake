add_test( myfunctions.add [==[/home/dongchansong/C_C++_Projects/Ex1/build/mytests]==] [==[--gtest_filter=myfunctions.add]==] --gtest_also_run_disabled_tests)
set_tests_properties( myfunctions.add PROPERTIES WORKING_DIRECTORY [==[/home/dongchansong/C_C++_Projects/Ex1/build]==])
set( mytests_TESTS myfunctions.add)
