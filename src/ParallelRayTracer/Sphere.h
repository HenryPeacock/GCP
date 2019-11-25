#ifndef SPHERE_H
#define SPHERE_H

#include "Core.h"
#include "Object.h"
#include "Ray.h"

class Sphere : Object 
{
public:
	glm::vec3 ShadePixel(Ray ray, glm::vec3 intersect);
};

#endif