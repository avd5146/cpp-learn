cmake_minimum_required (VERSION 2.8.11)
project (app2_test)

set(HEADERS ./include ./../app_test/include/)
include_directories(${../common_custom_headers/})
include_directories(${HEADERS})

set(SOURCE src/${PROJECT_NAME}.cpp)
add_executable(${PROJECT_NAME}_exe ${SOURCE})
add_library(${PROJECT_NAME}_lib ${SOURCE})
target_link_libraries(${PROJECT_NAME}_exe app_test_lib)
