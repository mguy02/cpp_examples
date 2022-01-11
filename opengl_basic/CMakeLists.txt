cmake_minimum_required(VERSION 3.0)

project(OpenGLBasic)

# Binaries will be saved there
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

# Locate Threads
find_package(Threads REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)


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

message(hesllo)
message("${GLUT_LIBRARY}")

# Allow include to use paths relative to projct root
include_directories(${PROJECT_SOURCE_DIR})
include_directories( ${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIR} )
#include_directories(${PROJECT_SOURCE_DIR}/googletest/googletest/include)

# create target
#add_executable(run_tests tests/gtests.cpp ${GTESTS} ${SRC_FILES})
add_executable(project ${SRC_MAIN} ${SRC_FILES})

# link run_tests to gtest and pthread
#target_link_libraries(run_tests ${CMAKE_SOURCE_DIR}/build_gtest/lib/libgtest.a pthread)
target_link_libraries(project ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})