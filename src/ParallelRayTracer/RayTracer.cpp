#include "RayTracer.h"

glm::vec4 RayTracer::TraceRay(shared<Ray> _ray)
{
	// Find first object hit by ray
	//	- Check all objects in the scene
	//	- Call Intersecting sphere 
	//	- If hit, record distance
	//	- Shortest dist is the one we want
	
	shared<RayDetails> details = makesh<RayDetails>();
	details->SetIsIntersecting(false);
	for (int i = 0; i < m_spheres.size(); i++)
	{
		shared<RayDetails> tempDetails = IntersectingSphere(_ray, m_spheres.at(i));
		if (tempDetails->GetIsIntersecting())
		{
			if (details->GetIsIntersecting())
			{
				if (tempDetails->GetIntersectDistance() < details->GetIntersectDistance())
				{
					details->SetIntersectDistance(tempDetails->GetIntersectDistance());
					details->SetColour(m_lights.at(0)->GetLighting(m_spheres.at(i), _ray, tempDetails));
					//details->SetColour(m_spheres.at(i)->GetColour());
				}
			}
			else
			{
				details->SetIsIntersecting(true);
				details->SetIntersectDistance(tempDetails->GetIntersectDistance());
				details->SetColour(m_lights.at(0)->GetLighting(m_spheres.at(i), _ray, tempDetails));
				//details->SetColour(m_spheres.at(i)->GetColour());
			}
		}
	}
	if (details->GetIsIntersecting())
	{
		// ToDo
		// Call objects shading method?? 
		// Probably wrong
		return details->GetColour();
	}
	else
	{
		return glm::vec4(20.0f, 20.0f, 20.0f, 0.0f); // ToDo: Change this to actual background colour
	}
}

glm::vec3 RayTracer::ClosestPoint(shared<Ray> _ray, glm::vec3 _queryPoint)
{
	// a = vector from cam pos to ray pos
	glm::vec3 a = _ray->GetOrigin() - m_camPos;
	// n = normalized direction vector of ray
	glm::vec3 n = glm::normalize(_ray->GetDirection());
	// P = Query Point
	glm::vec3 P = _queryPoint - m_camPos;
	// X = a + ((P - a) dot n)n
	glm::vec3 X = a + (glm::dot((P - a), n)*n);
	// X = Closest Point
	return X;
}

shared<RayDetails> RayTracer::IntersectingSphere(shared<Ray> _ray, shared<Sphere> _sphere)
{
	// Define the return class
	shared<RayDetails> returnValue = makesh<RayDetails>();

	// Check if ray origin is inside of the sphere, it is is then error
	float distance = glm::distance(_ray->GetOrigin(), _sphere->GetPosition());
	if (distance < _sphere->GetRadius())
	{
		returnValue->SetIsIntersecting(false);
		return returnValue;
	}

	// Find the closest point on the ray to the centre of the sphere
	glm::vec3 closest = ClosestPoint(_ray, _sphere->GetPosition());

	// ToDo
	// Check if the closest point is in front or behind of the ray's origin/ direction
	//	- Reject if intersection is behind ray's origin and direction points away from it
	//	- This prevents us from drawing objects that are behind the camera 


	// Work out distance from the closest point on the line to the sphere's centre
	distance = glm::distance(closest, _sphere->GetPosition());


	// Perform the 3 checks
	//	 if (||P - X|| <= R) ray intersects sphere else it doesn't
	//	 Closest intersection point:
	//		a + (((P-a) dot n) - x)n
	//			x = sqrt(r� - d�)
	//		d = ||P - a - ((P - a) dot n)n||
	if (distance > _sphere->GetRadius())
	{
		returnValue->SetIsIntersecting(false);
		return returnValue;
	}
	else
	{
		// We have collided, hooray!
		returnValue->SetIsIntersecting(true);
		// a = vector from cam pos to ray pos
		glm::vec3 a = _ray->GetOrigin() - m_camPos;
		// n = normalized direction vector of ray
		glm::vec3 n = glm::normalize(_ray->GetDirection());
		// P = Query Point
		glm::vec3 P = _sphere->GetPosition() - m_camPos;
		// d = ||P - a - ((P - a) dot n)n||
		glm::vec3 dirVec = P - a - (glm::dot((P - a), n)*n);
		float d = abs(glm::length(dirVec));
		// x = sqrt(r� - d�)
		float x = glm::sqrt((_sphere->GetRadius()*_sphere->GetRadius()) - (d*d));
		
		// hit = closest point - n*x for reasons?
		glm::vec3 hit = closest - n * x;
		returnValue->SetIntersectDistance(glm::distance(_ray->GetOrigin(), hit));
		returnValue->SetNormal(GetSphereNormal(_sphere, hit));
		return returnValue;
	}
}

glm::vec3 RayTracer::GetSphereNormal(shared<Sphere> _sphere, glm::vec3 _samplePoint)
{
	glm::vec3 returnValue = _sphere->GetPosition() - _samplePoint;
	glm::normalize(returnValue);
	return returnValue;
}
