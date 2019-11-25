#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "Core.h"
#include "Ray.h"
#include "macros.h"

class RayTracer
{
public:
	// Trace a ray
	glm::vec3 TraceRay(shared<Ray> _ray);
	// Get the closest point on a ray
	glm::vec3 ClosestPoint(shared<Ray> _ray, glm::vec3 _queryPoint);
	// Ray-sphere intersection
	float IntersectingSphere(shared<Ray> _ray, glm::vec3 _sphereCentre, float _radius);
	// Obtain normal of sphere
	glm::vec3 GetSphereNormal(glm::vec3 _centrePoint, glm::vec3 _samplePoint);
};

#endif