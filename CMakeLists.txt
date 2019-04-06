cmake_minimum_required(VERSION 3.6)
project( GridPhysics )

set(CMAKE_CXX_FLAGS_RELEASE "-O1 -g0 -Werror -std=c++11 -pthread")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3 -Wall -std=c++11 -pthread")

find_package(OpenGL REQUIRED)
find_package(Threads REQUIRED)

include_directories(include)
link_directories(${PROJECT_SOURCE_DIR}/include/lib-vc2015)
link_directories(${PROJECT_SOURCE_DIR}/include/lib-mingw)

set(GRID_SOURCES
        ${PROJECT_SOURCE_DIR}/src/grid/GridPoint.cpp
        ${PROJECT_SOURCE_DIR}/src/grid/GridPoint.h
        )

set(UTILS_SOURCES
        ${PROJECT_SOURCE_DIR}/src/utils/Color.h
        )

set(WINDOW_SOURCES
        ${PROJECT_SOURCE_DIR}/src/window/Window.h
        )

add_executable(GridPhysics
        src/grid_physics.cpp
        ${GRID_SOURCES}
        ${UTILS_SOURCES}
        ${WINDOW_SOURCES}
        )

include_directories(GridPhysics ${OPENGL_INCLUDE_DIR})

target_link_libraries(GridPhysics
        ${OPENGL_gl_LIBRARY}
        glfw3dll
        pthread
        ${CMAKE_THREAD_LIBS_INIT})
