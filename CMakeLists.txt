cmake_minimum_required(VERSION 3.23)
project(Voxel)

set(CMAKE_CXX_STANDARD 23)

add_executable(Voxel ResourceManagers/Shader.cpp src/main2.cpp src/glad.c Assets/Images/logo.h stb_image.h  Engine/Camera.cpp Engine/Camera.h Engine/Block.h Engine/Chunk.cpp Engine/Chunk.h)

find_package(OpenGL)
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)
find_package(fmt REQUIRED)
find_package(Boost 1.40)

include_directories(${OPENGL_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS} ${glm_INCLUDE_DIRS} ${Boost_INCLUDE_DIR} ${fmt_INCLUDE_DIRS} ./ ./include)
target_link_libraries(Voxel ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES} ${GLEW_LIBRARIES} ${Boost_LIBRARIES} ${glm_LIBRARIES} fmt::fmt)


