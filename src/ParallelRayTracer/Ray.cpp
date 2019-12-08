#include "Ray.h"

void Ray::multiplyByProjection(glm::mat4 _inverseProjectionMatrix)
{
	// Turn the vectors from 3 to 4 so that they can be multiplied by the matrix
	glm::vec4 tempOrigin = glm::vec4(m_origin, 0.0f);
	glm::vec4 tempDirection = glm::vec4(m_direction, 0.0f);

	// Multiply by the inverse projection matrix
	tempOrigin = tempOrigin * _inverseProjectionMatrix;
	tempDirection = tempDirection * _inverseProjectionMatrix;
	
	// Set origin and direction to new values (automatically deletes the 4th value)
	m_origin = tempOrigin;
	m_direction = tempDirection;
}
