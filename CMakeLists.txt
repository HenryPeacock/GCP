cmake_minimum_required(VERSION 2.6)
project(PARALLELRAYTRACER)

add_library(ParallelRayTracer
	src/ParallelRayTracer/macros.h
	src/ParallelRayTracer/Core.h
	src/ParallelRayTracer/Keyboard.h
	src/ParallelRayTracer/Core.cpp
	src/ParallelRayTracer/Keyboard.cpp
	src/ParallelRayTracer/ParallelRayTracer.h
)
target_link_libraries(ParallelRayTracer SDL2 opengl32 glew32)

add_executable(exec
	src/exec/main.cpp
)
target_link_libraries(exec ParallelRayTracer)