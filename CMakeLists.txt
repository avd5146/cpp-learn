cmake_minimum_required (VERSION 3.0.9)
project (cpp_learn CXX)

# set(CMAKE_COLOR_DIAGNOSTICS ON)
set(COMMON_LIBS ./common_custom_headers/)
add_subdirectory(app_test)
add_subdirectory(app2_test)
add_subdirectory(common_custom_headers)
add_subdirectory(1_primitive_types)
add_subdirectory(base2_bitcalc)
add_subdirectory(inheritance)
add_subdirectory(clockWorks)
add_subdirectory(threading)
add_subdirectory(from_bard/gopro_telemetry_extractor)
add_subdirectory(roman2string)
add_subdirectory(next_permutation)
add_subdirectory(linked_list)
add_subdirectory(topKfrequent)
add_subdirectory(longestConsecSeq)
add_subdirectory(palindrome_string)
add_subdirectory(listSum)
add_subdirectory(include_test)
add_subdirectory(trees)
add_subdirectory(lru_cache)
add_subdirectory(binary_search)
add_subdirectory(atlantic_pacific)
add_subdirectory(treasure_island)
add_subdirectory(CircularBuffer)
add_subdirectory(surrounded)
add_subdirectory(trie)