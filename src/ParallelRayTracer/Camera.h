#ifndef CAMERA_H
#define CAMERA_H

#include "Ray.h"

class Camera
{
public:
	Ray CreateRay(glm::ivec2 _pixelPair);
};


#endif