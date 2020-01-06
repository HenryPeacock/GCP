#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "Core.h"
#include "Ray.h"
#include "macros.h"
#include "Sphere.h"
#include <vector>

class RayDetails
{
public:
	// Getters and Setters
	bool GetIsIntersecting() { return m_isIntersecting; };
	void SetIsIntersecting(bool _isIntersecting) { m_isIntersecting = _isIntersecting; };
	// 
	float GetIntersectDistance() { return m_intersectDistance; };
	void SetIntersectDistance(float _intersectDistance) { m_intersectDistance = _intersectDistance; };
	//
	glm::vec3 GetColour() { return m_colour; };
	glm::vec3 SetColour(glm::vec3 _colour) { m_colour = _colour; };
private:
	bool m_isIntersecting;
	float m_intersectDistance;
	glm::vec3 m_colour;
};

class RayTracer
{
public:
	// Trace a ray
	glm::vec3 TraceRay(shared<Ray> _ray);
	// Get the closest point on a ray
	glm::vec3 ClosestPoint(shared<Ray> _ray, glm::vec3 _queryPoint);
	// Ray-sphere intersection
	shared<RayDetails> IntersectingSphere(shared<Ray> _ray, shared<Sphere> _sphere);
	// Obtain normal of sphere
	glm::vec3 GetSphereNormal(glm::vec3 _centrePoint, glm::vec3 _samplePoint);
	// Add an object
	void AddSphere(shared<Sphere> _sphere) { m_spheres.push_back(_sphere); };
private:
	glm::vec3 m_camPos = glm::vec3(0.0f, 0.0f, 0.0f);
	std::vector<shared<Sphere>> m_spheres;
	float m_highestDistance;
};

#endif