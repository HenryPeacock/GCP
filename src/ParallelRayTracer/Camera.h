#ifndef CAMERA_H
#define CAMERA_H

#include "Ray.h"
#include "macros.h"

class Camera
{
public:
	shared<Ray> CreateRay(glm::ivec2 _pixelPair);
private:
};


#endif