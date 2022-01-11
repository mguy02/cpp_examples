cmake_minimum_required(VERSION 3.0)

project(Calculator)

# Binaries will be saved there
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

set(CMAKE_CXX_STANDARD 11) # set Cpp11

# Set coverage compilation option if in UNIX
if (UNIX)
    find_program(GCOV_PATH gcov REQUIRED)
    find_program(LCOV_PATH lcov REQUIRED)
    set(CMAKE_CXX_FLAGS "--coverage")
endif(UNIX)

# Locate Threads
find_package(Threads REQUIRED)

# Main project entry point
file(GLOB SRC_MAIN
    "src/main.cpp"
)

# Main project sources, without main
file(GLOB_RECURSE SRC_FILES
    "src/**.cpp"
)
list(REMOVE_ITEM SRC_FILES ${SRC_MAIN})

# Tests sources
file(GLOB GTESTS
    "tests/**.cpp"
)

# Allow include to use paths relative to projct root
include_directories(${PROJECT_SOURCE_DIR})
#include_directories(${PROJECT_SOURCE_DIR}/googletest/googletest/include)

# create target
#add_executable(run_tests tests/gtests.cpp ${GTESTS} ${SRC_FILES})
add_executable(project ${SRC_MAIN} ${SRC_FILES})

# link run_tests to gtest and pthread
#target_link_libraries(run_tests ${CMAKE_SOURCE_DIR}/build_gtest/lib/libgtest.a pthread)
