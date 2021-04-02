cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(Geometry)

set(CMAKE_CXX_STANDARD 14)

option(BUILD_EXAMPLES "Build Examples" OFF)

set(SOURCE_FOLDERS ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_FOLDERS ${PROJECT_SOURCE_DIR}/include)

set(SOURCE_FILES 
	${SOURCE_FOLDERS}/point.cpp
	${SOURCE_FOLDERS}/geo_utils.cpp
	${SOURCE_FOLDERS}/line.cpp)
set(HEADER_FILES 
	${INCLUDE_FOLDERS}/point.hpp
	${INCLUDE_FOLDERS}/geo_utils.hpp
	${INCLUDE_FOLDERS}/line.hpp)

add_library(geometry STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(geometry PUBLIC ${INCLUDE_FOLDERS})

if(${BUILD_EXAMPLES})
	add_executable(tutorial-1 ./tutorial/main.cpp)
	target_include_directories(tutorial-1 PUBLIC ${INCLUDE_FOLDERS})
endif()