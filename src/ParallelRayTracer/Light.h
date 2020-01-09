#ifndef LIGHT_H
#define LIGHT_H

#include "Core.h"
#include "Object.h"
#include "macros.h"
#include "Sphere.h"
//#include "RayTracer.h"

class RayDetails;

class Light : public Object
{
public:
	Light();
	Light(glm::vec3 _position, glm::vec3 _rotation, glm::vec4 _colour);
	glm::vec4 GetLighting(shared<Sphere> _sphere, shared<Ray> _ray, shared<RayDetails> _details);
};

#endif