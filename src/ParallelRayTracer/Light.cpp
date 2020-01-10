#include "Light.h"
#include "RayTracer.h"

Light::Light()
{
	m_position = glm::vec3(0.0f, 0.0f, 0.0f);
	m_rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	m_colour = glm::vec4(255.0f, 255.0f, 255.0f,0.0f);
}

Light::Light(glm::vec3 _position, glm::vec3 _rotation, glm::vec4 _colour)
{
	m_position = _position;
	m_rotation = _rotation;
	m_colour = _colour;
}

glm::vec4 Light::GetLighting(shared<Sphere> _sphere, shared<Ray> _ray, shared<RayDetails> _details)
{
	// http://www.robots.ox.ac.uk/~att/index.html
	glm::vec3 lightVector = (_sphere->GetPosition() - m_position);
	glm::vec3 normalLV = glm::normalize(lightVector);

	float DOT = glm::abs(glm::dot(_details->GetNormal(), normalLV));

	float result = ((0.8f*_sphere->GetAmbient()) + (0.9f*(DOT)) + (0.4f*glm::pow(DOT, 100.0f)));
	result *= (3.0f/ glm::length(lightVector));

	return (_sphere->GetColour() * result);
}
