# -------------------------------------------------------------------->
# cmake_minimum_required(VERSION 3.15)
# project(ray_lib_gane)

# find_package(raylib 3.0 REQUIRED) # Requires at least version 3.0

# set(CMAKE_C_STANDARD 11) # Requires C11 standard

# add_executable(${PROJECT_NAME} src/main.cpp)

# target_link_libraries(${PROJECT_NAME} raylib)

# # Checks if OSX and links appropriate frameworks (only required on MacOS)
# if (APPLE)
#     target_link_libraries(${PROJECT_NAME} "-framework IOKit")
#     target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
#     target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
# endif()
# -------------------------------------------------------------------->

cmake_minimum_required(VERSION 3.15)
project(game_of_life)

set(CMAKE_CXX_STANDARD 20)

set(RAYLIB_LOCAL_LIB "${CMAKE_SOURCE_DIR}/lib/libraylib.a")
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src/")

file(GLOB SOURCES
    ${SRC_DIR}grid/*.cpp
    ${SRC_DIR}title/*.cpp
    ${SRC_DIR}pause/*.cpp
    ${SRC_DIR}gameplay/*.cpp
)

add_executable(${PROJECT_NAME} ${SRC_DIR}main.cpp ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${RAYLIB_LOCAL_LIB})

if(APPLE)
    find_library(COCOA_LIBRARY Cocoa REQUIRED)
    find_library(IOKIT_LIBRARY IOKit REQUIRED)
    find_library(OPENGL_LIBRARY OpenGL REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${COCOA_LIBRARY} ${IOKIT_LIBRARY} ${OPENGL_LIBRARY})
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME} PRIVATE -g)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(${PROJECT_NAME} PRIVATE -O3 -DNDEBUG)
else()
    message(WARNING "Unknown build type: ${CMAKE_BUILD_TYPE}, defaulting to Debug.")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
