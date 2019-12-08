#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "Core.h"
#include "Ray.h"
#include "macros.h"

class RayDetails
{
public:
	// Getters and Setters
	bool GetIsIntersecting() { return m_isIntersecting; };
	void SetIsIntersecting(bool _isIntersecting) { m_isIntersecting = _isIntersecting; };
	// 
	float GetIntersectDistance() { return m_intersectDistance; };
	void SetIntersectDistance(float _intersectDistance) { m_intersectDistance = _intersectDistance; };

private:
	bool m_isIntersecting;
	float m_intersectDistance;
};

class RayTracer
{
public:
	// Trace a ray
	glm::vec3 TraceRay(shared<Ray> _ray);
	// Get the closest point on a ray
	glm::vec3 ClosestPoint(shared<Ray> _ray, glm::vec3 _queryPoint);
	// Ray-sphere intersection
	shared<RayDetails> IntersectingSphere(shared<Ray> _ray, glm::vec3 _sphereCentre, float _radius);
	// Obtain normal of sphere
	glm::vec3 GetSphereNormal(glm::vec3 _centrePoint, glm::vec3 _samplePoint);
private:
	glm::vec3 m_camPos = glm::vec3(0.0f, 0.0f, 0.0f);
};

#endif