cmake_minimum_required (VERSION 3.0.9)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

set(APP_HEADERS ./include)
include_directories(${../common_custom_headers/})
include_directories(${APP_HEADERS})

file(GLOB SOURCES src/*.cpp)
set(EXE src/${PROJECT_NAME}_exe.cpp)
add_library(${PROJECT_NAME}_lib ${SOURCES})
add_executable(${PROJECT_NAME}_exe ${EXE})

# target_include_directories(${PROJECT_NAME}_lib PRIVATE include)
# target_include_directories(${PROJECT_NAME}_exe PRIVATE include)

target_link_libraries(${PROJECT_NAME}_lib INTERFACE common_custom_headers_lib)
target_link_libraries(${PROJECT_NAME}_exe ${PROJECT_NAME}_lib)

