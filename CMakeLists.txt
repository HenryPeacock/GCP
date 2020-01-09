cmake_minimum_required(VERSION 2.6)
project(PARALLELRAYTRACER)

include_directories(src)

add_library(ParallelRayTracer
	src/ParallelRayTracer/ParallelRayTracer.h
	src/ParallelRayTracer/macros.h
	src/ParallelRayTracer/Core.h
	src/ParallelRayTracer/Keyboard.h
	src/ParallelRayTracer/Ray.h
	src/ParallelRayTracer/Object.h
	src/ParallelRayTracer/Camera.h
	src/ParallelRayTracer/RayTracer.h
	src/ParallelRayTracer/Sphere.h
	src/ParallelRayTracer/Light.h

	src/ParallelRayTracer/Core.cpp
	src/ParallelRayTracer/Keyboard.cpp
	src/ParallelRayTracer/Ray.cpp
	src/ParallelRayTracer/Object.cpp
	src/ParallelRayTracer/Camera.cpp
	src/ParallelRayTracer/RayTracer.cpp
	src/ParallelRayTracer/Sphere.cpp
	src/ParallelRayTracer/Light.cpp
)
target_link_libraries(ParallelRayTracer SDL2 opengl32 glew32)

add_executable(exec
	src/exec/main.cpp
)
target_link_libraries(exec ParallelRayTracer)