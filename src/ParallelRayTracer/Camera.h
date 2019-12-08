#ifndef CAMERA_H
#define CAMERA_H

#include "Ray.h"
#include "macros.h"

class Camera
{
public:
	Camera(glm::ivec2 _windowDimensions);
	shared<Ray> CreateRay(glm::ivec2 _pixelPair);
private:
	glm::ivec2 m_windowDimensions;
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;
	glm::mat4 m_inverseProjectionMatrix;
};


#endif