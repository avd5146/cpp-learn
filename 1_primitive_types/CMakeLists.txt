cmake_minimum_required (VERSION 3.0.9)
project (1_primitive_types)

set(APP_HEADERS ./include)
include_directories(${../common_custom_headers/})
include_directories(${APP_HEADERS})

set(SOURCE src/${PROJECT_NAME}.cpp)
set(EXE src/${PROJECT_NAME}_exe.cpp)
add_library(${PROJECT_NAME}_lib ${SOURCE})
add_executable(${PROJECT_NAME}_exe ${EXE})
target_link_libraries(${PROJECT_NAME}_exe ${PROJECT_NAME}_lib)

