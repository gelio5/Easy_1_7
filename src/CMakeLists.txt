set(SOURCES
        Regular.cpp
        Regular.h)
add_library(Regular ${SOURCES})
target_include_directories(Regular PUBLIC ${SRC_ROOT_DIR})
source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SOURCES})
add_subdirectory(tests)