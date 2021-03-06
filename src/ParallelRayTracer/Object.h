#ifndef OBJECT_H
#define OBJECT_H

#include "Core.h"

class Object
{
public:
	// Getters and Setters
	glm::vec3 GetPosition() { return m_position; };
	void SetPosition(glm::vec3 _position) { m_position = _position; };
	//
	glm::vec3 GetRotation() { return m_rotation; };
	void SetRotation(glm::vec3 _rotation) { m_rotation = _rotation; };
	//
	glm::vec3 GetScale() { return m_scale; };
	void SetScale(glm::vec3 _scale) { m_scale = _scale; };
	//
	glm::vec4 GetColour() { return m_colour; };
	void SetColour(glm::vec4 _colour) { m_colour = _colour; };
	//
	float GetAmbient() { return m_ambient; };
	void SetAmbient(float _ambient) { m_ambient = _ambient; };
protected:
	glm::vec3 m_position, m_rotation, m_scale;
	glm::vec4 m_colour;
	float m_ambient;
};

#endif