cmake_minimum_required( VERSION 3.6 )

project( MazeRaycaster )

find_package( OpenGL REQUIRED )

include_directories( ${OPENGL_INCLUDE_DIRS} )
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/MazeRaycaster)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/MazeRaycaster)

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )
add_subdirectory( glfw )

if( MSVC )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup" )
endif()

set( MAZERAYCASTER-SRC
	src/Entity.cpp
	src/Game.cpp
	src/Input.cpp
	src/Map.cpp
	src/Player.cpp
	src/Raycaster.cpp
	src/Renderer.cpp
	src/Vector2f.cpp
	src/glad.c
     )
     
add_executable( MazeRaycaster WIN32 ${MAZERAYCASTER-SRC} )
target_link_libraries( MazeRaycaster ${OPENGL_LIBRARIES} glfw )

if( MSVC )
	set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT MazeRaycaster )
endif()