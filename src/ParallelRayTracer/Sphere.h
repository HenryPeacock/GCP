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
	//
	glm::vec3 GetColour() { return m_colour; };
	void SetColour(glm::vec3 _colour) { m_colour = _colour; };
private:
	float m_radius;
	glm::vec3 m_colour;
};

#endif