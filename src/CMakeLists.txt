file(GLOB WOS_SRC "*.cpp")
list(REMOVE_ITEM WOS_SRC "main.cpp")

add_library(WO1SLib ${WOS_SRC})
target_include_directories(WO1SLib PRIVATE common)
add_executable(WayOut1Solver main.cpp)
target_link_libraries(WayOut1Solver WO1SLib)

add_library(WO2SLib ${WOS_SRC})
target_compile_definitions(WO2SLib PUBLIC WAYOUT2)
target_include_directories(WO2SLib PRIVATE common)
add_executable(WayOut2Solver main.cpp)
target_link_libraries(WayOut2Solver WO2SLib)

add_executable(WayOut1Logging EXCLUDE_FROM_ALL ${WOS_SRC} main.cpp)
target_compile_definitions(WayOut1Logging PRIVATE LOGGING)
target_include_directories(WayOut1Logging PRIVATE common)

add_executable(WayOut2Logging EXCLUDE_FROM_ALL ${WOS_SRC} main.cpp)
target_compile_definitions(WayOut2Logging PRIVATE WAYOUT2 LOGGING)
target_include_directories(WayOut2Logging PRIVATE common)
