cmake_minimum_required(VERSION 3.1)
project(study)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG F:/Study/client/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG F:/Study/client/Debug)

add_executable(studyExample ${CMAKE_CURRENT_SOURCE_DIR}/studycpp/main.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/studycpp/Container/include)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB Container_SRC
${CMAKE_CURRENT_SOURCE_DIR}/studycpp/Container/include/*.h
${CMAKE_CURRENT_SOURCE_DIR}/studycpp/Container/src/*.cpp
)
add_library(Container SHARED
	${Container_SRC}
)
target_link_libraries(studyExample Container)