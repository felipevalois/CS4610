cmake_minimum_required(VERSION 3.5)

project(Part-A)

set(CMAKE_CXX_FLAGS "-std=c++11")

#Mac
add_definitions(-Wno-deprecated-declarations)

find_package(OpenGL REQUIRED)
set(GLFW_INCLUDE "/usr/local/Cellar/glfw/3.3.2/include/")
set(GLEW_INCLUDE "/usr/local/Cellar/glew/2.1.0_1/include/")
set(GLFW_LIB "/usr/local/Cellar/glfw/3.3.2/lib/libglfw.3.3.dylib")
set(GLEW_LIB "/usr/local/Cellar/glew/2.1.0_1/lib/libGLEW.2.1.0.dylib")

set(INCLUDE_DIRS ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE} ${GLFW_INCLUDE})
set(LIBRARIES ${OPENGL_LIBRARIES} ${GLEW_LIB} ${GLFW_LIB})

include_directories(${INCLUDE_DIRS})

file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_executable(Part-A ${SOURCE_FILES} ${INCLUDE_FILES})
target_link_libraries(Part-A ${LIBRARIES})
