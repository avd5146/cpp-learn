cmake_minimum_required (VERSION 3.0.9)
project (app2_test)

set(HEADERS ./include ./../app_test/include/)
include_directories(${../common_custom_headers/})
include_directories(${HEADERS})

set(SOURCE src/${PROJECT_NAME}.cpp)
add_executable(${PROJECT_NAME}_exe ${SOURCE})
add_library(${PROJECT_NAME}_lib ${SOURCE})
# Note: lib dependency of external lib also needs to be linked here.
target_link_libraries(${PROJECT_NAME}_lib common_custom_headers_lib)

target_link_libraries(${PROJECT_NAME}_exe app_test_lib)
