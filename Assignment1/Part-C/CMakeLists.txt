cmake_minimum_required(VERSION 3.5)

project(Part-C)

set(CMAKE_CXX_FLAGS "-std=c++11")

add_definitions(-Wno-deprecated-declarations)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(GLFW_INCLUDE "/usr/local/Cellar/glfw/3.3.2/include/")
set(GLEW_INCLUDE "/usr/local/Cellar/glew/2.1.0_1/include/")
set(GLFW_LIB "/usr/local/Cellar/glfw/3.3.2/lib/libglfw.3.3.dylib")
set(GLEW_LIB "/usr/local/Cellar/glew/2.1.0_1/lib/libGLEW.2.1.0.dylib")

set(INCLUDE_DIRS ${GLFW_INCLUDE} ${GLEW_INCLUDE} ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR} )
set(LIBRARIES ${GLFW_LIB} ${GLEW_LIB} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

include_directories(${INCLUDE_DIRS})

file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_executable(Part-C ${SOURCE_FILES} ${INCLUDE_FILES})
target_link_libraries(Part-C ${LIBRARIES})
