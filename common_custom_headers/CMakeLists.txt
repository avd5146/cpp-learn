cmake_minimum_required (VERSION 3.0.9)
project(common_custom_headers CXX)

set(HEADERS ./)
include_directories(${HEADERS})
add_library(${PROJECT_NAME}_lib ${HEADERS})

# does not identify linker type if below line is missing
set_target_properties(${PROJECT_NAME}_lib PROPERTIES LINKER_LANGUAGE CXX)