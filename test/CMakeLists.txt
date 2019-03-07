find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${TEST_SOURCE_DIR}
                    ../src
                    ${Boost_INCLUDE_DIRS}
                    )

add_definitions(-DBOOST_TEST_DYN_LINK)

add_library(WOSTestLib test_common.cpp)

add_executable(WO1S1Test test_wo1s1.cpp)
add_executable(WO1S2Test test_wo1s2.cpp)
add_executable(WO1S3Test test_wo1s3.cpp)
add_executable(WO1S4Test test_wo1s4.cpp)
add_executable(WO1S5Test test_wo1s5.cpp)
add_executable(WO1S6Test test_wo1s6.cpp)

add_executable(WO2S1Test test_wo2s1.cpp)
add_executable(WO2S2Test test_wo2s2.cpp)
add_executable(WO2S3Test test_wo2s3.cpp)
add_executable(WO2S4Test test_wo2s4.cpp)
add_executable(WO2S5Test test_wo2s5.cpp)
add_executable(WO2S6Test test_wo2s6.cpp)
add_executable(WO2S7Test test_wo2s7.cpp)

target_link_libraries(WO1S1Test WOSTestLib WO1SLib ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(WO1S2Test WOSTestLib WO1SLib ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(WO1S3Test WOSTestLib WO1SLib ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(WO1S4Test WOSTestLib WO1SLib ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(WO1S5Test WOSTestLib WO1SLib ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(WO1S6Test WOSTestLib WO1SLib ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

target_link_libraries(WO2S1Test WOSTestLib WO2SLib ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(WO2S2Test WOSTestLib WO2SLib ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(WO2S3Test WOSTestLib WO2SLib ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(WO2S4Test WOSTestLib WO2SLib ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(WO2S5Test WOSTestLib WO2SLib ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(WO2S6Test WOSTestLib WO2SLib ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(WO2S7Test WOSTestLib WO2SLib ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(NAME WO1S1Test COMMAND WO1S1Test)
add_test(NAME WO1S2Test COMMAND WO1S2Test)
add_test(NAME WO1S3Test COMMAND WO1S3Test)
add_test(NAME WO1S4Test COMMAND WO1S4Test)
add_test(NAME WO1S5Test COMMAND WO1S5Test)
add_test(NAME WO1S6Test COMMAND WO1S6Test)

add_test(NAME WO2S1Test COMMAND WO2S1Test)
add_test(NAME WO2S2Test COMMAND WO2S2Test)
add_test(NAME WO2S3Test COMMAND WO2S3Test)
add_test(NAME WO2S4Test COMMAND WO2S4Test)
add_test(NAME WO2S5Test COMMAND WO2S5Test)
add_test(NAME WO2S6Test COMMAND WO2S6Test)
add_test(NAME WO2S7Test COMMAND WO2S7Test)

set_target_properties(WO1S1Test WO1S2Test WO1S3Test WO1S4Test WO1S5Test WO1S6Test
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/test")

set_target_properties(WO2S1Test WO2S2Test WO2S3Test WO2S4Test WO2S5Test WO2S6Test WO2S7Test
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/test")


