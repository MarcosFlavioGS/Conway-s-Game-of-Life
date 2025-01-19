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

set(CMAKE_CXX_STANDARD 20) # Requires C++20 standard

# Add the path to your local library
set(RAYLIB_LOCAL_LIB "${CMAKE_SOURCE_DIR}/lib/libraylib.a")

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src/")

file(GLOB SOURCES
  	${SRC_DIR}grid/*.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SRC_DIR}main.cpp ${SOURCES})

# Link the local static library instead of the system-installed one
target_link_libraries(${PROJECT_NAME} PRIVATE ${RAYLIB_LOCAL_LIB})

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
endif()
