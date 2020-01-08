#include "Camera.h"

Camera::Camera(glm::ivec2 _windowDimensions)
{
	m_windowDimensions = _windowDimensions;
	
	// Projection matrix: // Source: http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/#the-projection-matrix
	// Generates a really hard-to-read matrix, but a normal, standard 4x4 matrix nonetheless
	glm::mat4 m_projectionMatrix = glm::perspective(
		glm::radians(60.0f), // The vertical Field of View, in radians: the amount of "zoom". Think "camera lens". Usually between 90° (extra wide) and 30° (quite zoomed in)
		4.0f / 3.0f,       // Aspect Ratio. Depends on the size of your window. Notice that 4/3 == 800/600 == 1280/960, sounds familiar ?
		0.1f,              // Near clipping plane. Keep as big as possible, or you'll get precision issues.
		100.0f             // Far clipping plane. Keep as little as possible.
	);
	m_inverseProjectionMatrix = glm::inverse(m_projectionMatrix);

	// View Matrix
	// ToDo: Set that to forward vector and other to up vector
	m_viewMatrix = glm::lookAt(m_position, /*THIS*/glm::vec3(0.0f,0.0f,glm::radians(90.0f)), /*ANDTHIS*/glm::vec3(0.0f, glm::radians(90.0f),0.0f));
	m_inverseViewMatrix = glm::inverse(m_viewMatrix);
}

shared<Ray> Camera::CreateRay(glm::ivec2 _pixelPair)
{
	// Define the return class
	shared<Ray> rtn = makesh<Ray>();

	
	float x = _pixelPair.x - (m_windowDimensions.x / 2);
	float y = _pixelPair.y - (m_windowDimensions.y / 2);

	// ToDo, move to camera constructor, change to being based on FOV not set at 60
	float cameraDistance = (m_windowDimensions.x) / (glm::tan(glm::radians(60.0f / 2.0f)));

	glm::vec3 tempPoint = glm::vec3(x, y, cameraDistance);
	glm::vec3 tempDir = tempPoint - m_position;

	rtn->SetOrigin(m_position);
	rtn->SetDirection(tempDir);
	return rtn;
	

	// Old stuff (More advanced than necessary) ToDo: Can try to reimplement
	/*
	// Viewing volume is a cube from -1 to 1 in each dimension
	// NDC is left-handed
	rtn->SetOrigin(glm::vec3(_pixelPair.x/m_windowDimensions.x, _pixelPair.y/m_windowDimensions.y, -1));
	rtn->SetDirection(glm::vec3(0.0f, 0.0f, 1.0f));
	// Multiply coords by inverse projection matrix and divide by w
	rtn->multiplyByMatrix(m_inverseProjectionMatrix, true);
	// Multiple coords by inverse view matrix
	rtn->multiplyByMatrix(m_inverseViewMatrix, false);
	return rtn;
	*/
}
