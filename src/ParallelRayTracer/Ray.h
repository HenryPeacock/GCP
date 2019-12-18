#ifndef RAY_H
#define RAY_H

#include "Core.h"
#include "macros.h"

class Ray
{
public:
	// Getters and Setters
	glm::vec3 GetOrigin() { return m_origin; };
	void SetOrigin(glm::vec3 _origin) { m_origin = _origin; };
	// 
	glm::vec3 GetDirection() { return m_direction; };
	void SetDirection(glm::vec3 _direction) { m_direction = _direction; };

	// Function to convert to eye space
	void multiplyByMatrix(glm::mat4 _inverseMatrix, bool _isProjection);
private:
	glm::vec3 m_origin;
	glm::vec3 m_direction;
};

#endif