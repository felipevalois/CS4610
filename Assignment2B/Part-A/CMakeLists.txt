cmake_minimum_required(VERSION 3.5)

project(Part-A)
set(CMAKE_CXX_FLAGS "-std=c++11")

set(APPLE TRUE)

# Suppress warnings of the deprecation of glut functions on macOS.
add_definitions(-Wno-deprecated-declarations)

# Find OpenGL
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Find include and library for GLFW and GLEW
set(GLFW_INCLUDE "/usr/local/Cellar/glfw/3.3.2/include/")
set(GLEW_INCLUDE "/usr/local/Cellar/glew/2.1.0_1/include/")
set(GLFW_LIB "/usr/local/Cellar/glfw/3.3.2/lib/libglfw.3.3.dylib")
set(GLEW_LIB "/usr/local/Cellar/glew/2.1.0_1/lib/libGLEW.2.1.0.dylib")

# OPENGL_INCLUDE_DIR and OPENGL_LIBRARIES are CMake built-in variables defined when the packages are found
set(INCLUDE_DIRS include ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR} ${GLEW_INCLUDE} ${GLFW_INCLUDE} )
set(LIBRARIES ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLEW_LIB} ${GLFW_LIB})

# Add the list of include paths to be used to search for include files.
include_directories(${INCLUDE_DIRS})

# Search all the .cpp files in the directory where CMakeLists lies and set them to ${SOURCE_FILES}.
# Search all the .h files in the directory where CMakeLists lies and set them to ${INCLUDE_FILES}.
file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

# Add the executable Part-A to be built from the source files.
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${INCLUDE_FILES})

# Link the executable to the libraries.
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
