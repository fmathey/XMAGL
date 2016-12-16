cmake_minimum_required(VERSION 3.6)

project(XMAGL)

set(XMAGL_VERSION_MAJOR 0)
set(XMAGL_VERSION_MINOR 0)
set(XMAGL_VERSION_PATCH 4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_net REQUIRED)

include_directories(
    ${OPENGL_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIR}
    ${SDL2_MIXER_INCLUDE_DIR}
    ${SDL2_NET_INCLUDE_DIR}
    ${SDL2_TTF_INCLUDE_DIR}
    ${GLM_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/includes
    ${PROJECT_SOURCE_DIR}/externals/tiny_obj_loader
)

set(
    XMAGL_LIBRARIES
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    ${SDL2_MIXER_LIBRARY}
    ${SDL2_NET_LIBRARY}
    ${SDL2_TTF_LIBRARY}
)

file(
    GLOB_RECURSE XMAGL_SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/sources/*.cpp
    ${PROJECT_SOURCE_DIR}/externals/tiny_obj_loader/*.c*
)

add_subdirectory(applications)