add_test( GetNumberOfRowTest.GetNumberOfRow [==[/home/dongchansong/C_C++_Projects/Ex1/build/myTest]==] [==[--gtest_filter=GetNumberOfRowTest.GetNumberOfRow]==] --gtest_also_run_disabled_tests)
set_tests_properties( GetNumberOfRowTest.GetNumberOfRow PROPERTIES WORKING_DIRECTORY [==[/home/dongchansong/C_C++_Projects/Ex1/build]==])
add_test( AddMatricesTest.AddMatrices [==[/home/dongchansong/C_C++_Projects/Ex1/build/myTest]==] [==[--gtest_filter=AddMatricesTest.AddMatrices]==] --gtest_also_run_disabled_tests)
set_tests_properties( AddMatricesTest.AddMatrices PROPERTIES WORKING_DIRECTORY [==[/home/dongchansong/C_C++_Projects/Ex1/build]==])
add_test( MultiplyMatricesTest.MultiplyMatrices [==[/home/dongchansong/C_C++_Projects/Ex1/build/myTest]==] [==[--gtest_filter=MultiplyMatricesTest.MultiplyMatrices]==] --gtest_also_run_disabled_tests)
set_tests_properties( MultiplyMatricesTest.MultiplyMatrices PROPERTIES WORKING_DIRECTORY [==[/home/dongchansong/C_C++_Projects/Ex1/build]==])
set( myTest_TESTS GetNumberOfRowTest.GetNumberOfRow AddMatricesTest.AddMatrices MultiplyMatricesTest.MultiplyMatrices)
