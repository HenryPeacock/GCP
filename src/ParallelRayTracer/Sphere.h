#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"
#include "Ray.h"

class Sphere : public Object 
{
public:
	glm::vec3 ShadePixel(Ray ray, glm::vec3 intersect);

	// Getters and Setters
	float GetRadius() { return m_radius; };
	void SetRadius(float _radius) { m_radius = _radius; };

private:
	float m_radius;
};

#endif