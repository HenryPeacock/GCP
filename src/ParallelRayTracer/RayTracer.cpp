#include "RayTracer.h"

glm::vec3 RayTracer::TraceRay(shared<Ray> _ray)
{
	return glm::vec3();
}

glm::vec3 RayTracer::ClosestPoint(shared<Ray> _ray, glm::vec3 _queryPoint)
{
	// a = vector from cam pos to ray pos
	glm::vec3 a = _ray->origin - m_camPos;
	// n = normalized direction vector of ray
	glm::vec3 n = glm::normalize(_ray->direction);
	// P = Query Point
	glm::vec3 P = _queryPoint - m_camPos;
	// X = a + ((P - a) dot n)n
	glm::vec3 X = a + (glm::dot((P - a), n)*n);
	// X = Closest Point
	return X;
}

float RayTracer::IntersectingSphere(shared<Ray> _ray, glm::vec3 _sphereCentre, float _radius)
{
	// Check if ray origin is inside of the sphere, it is is then error
	//	- http://www.miguelcasillas.com/?p=38
	glm::vec3 distanceVec = _sphereCentre - _ray->origin;
	float distance = glm::sqrt(glm::dot(distanceVec, distanceVec));
	if (distance < _radius)
	{
		return 0.0f;
	}

	// Find the closest point on the ray to the centre of the sphere
	glm::vec3 closest = ClosestPoint(_ray, _sphereCentre);

	// Check if the closest point is in front or behind of the ray's origin/ direction
	//	- Reject if intersection is behind ray's origin and direction points away from it
	//	- This prevents us from drawing objects that are behind the camera 
	// 

	//if (closest < _ray->origin)


	// Work out distance from the closest point on the line to the sphere's cente



	// Perform the 3 checks
	//	 if (||P - X|| <= R) ray intersects sphere else it doesn't
	//	 Closest intersection point:
	//		a + (((P-a) dot n) - x)n
	//			x = sqrt(r² - d²)
	//		d = ||P - a - ((P - a) dot n)n||


	return 0.0f;
}

glm::vec3 RayTracer::GetSphereNormal(glm::vec3 _centrePoint, glm::vec3 _samplePoint)
{
	return glm::vec3();
}
