cmake_minimum_required(VERSION 3.22)
project(HELLOAPP)
set(SRC_FILES 
    main.cpp 
    src/calc.cpp)
message(STATUS "SRC File has ${SRC_FILES}")
message("path is ${CMAKE_SOURCE_DIR}")
if(EXISTS ${CMAKE_SOURCE_DIR}/main.cpp)
    message("file exist")
else()
    message(FATAL_ERROR "file not exist")
endif()

add_subdirectory(${CMAKE_SOURCE_DIR}/lib)
add_executable(hellobinary ${SRC_FILES})
target_include_directories(hellobinary PUBLIC inc/ lib/)

target_link_libraries(hellobinary PUBLIC wifi_lib)