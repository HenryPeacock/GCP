#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "Core.h"
#include "Ray.h"

class RayTracer
{
public:
	glm::vec3 TraceRay(Ray _ray);
};

#endif