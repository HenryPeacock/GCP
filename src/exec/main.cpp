#include <ParallelRayTracer/ParallelRayTracer.h>

#include <cmath>
#include <iostream>
#include <time.h>

int main()
{
	// Ctrl + F "ToDo"

	srand(time(NULL));
	float windowX = 800.0f;
	float windowY = 600.0f;
	// Storage variables
	glm::ivec2 windowSize(windowX, windowY);
	glm::ivec3 pixelColour = glm::ivec3(255.0f, 0.0f, 0.0f);

	// Initialise the window
	if (!MCG::Init(windowSize))
	{
		return -1;
	}

	// Sets all pixels to a colour
	MCG::SetBackground(glm::ivec3(0.0f, 0.0f, 0.0f));

	// Determine where the pixel should be
	glm::ivec2 pixelPosition = windowSize / 2;

	// Draw the single pixel
	MCG::DrawPixel(pixelPosition, pixelColour);

	// Trying to draw a sphere :O

	// Make the variables
	Camera camera(windowSize);
	RayTracer tracer;
	shared<Sphere> sphere = makesh<Sphere>();
	sphere->SetPosition(glm::vec3(1.0f, 0.0f, 7.0f));
	sphere->SetRadius(1.5f);
	sphere->SetColour(glm::vec3(255.0f, 0.0f, 0.0f));
	tracer.AddSphere(sphere);
	shared<Sphere> sphere2 = makesh<Sphere>();
	sphere2->SetPosition(glm::vec3(0.0f, 0.0f, 6.0f));
	sphere2->SetRadius(1.0f);
	sphere2->SetColour(glm::vec3(0.0f, 255.0f, 0.0f));
	tracer.AddSphere(sphere2);
	shared<Sphere> sphere3 = makesh<Sphere>();
	sphere3->SetPosition(glm::vec3(0.0f, 1.0f, 6.5f));
	sphere3->SetRadius(1.5f);
	sphere3->SetColour(glm::vec3(0.0f, 0.0f, 255.0f));
	tracer.AddSphere(sphere3);
	// Pray?
	for (int i = 0; i < windowSize.x; i++)
	{
		for (int j = 0; j < windowSize.y; j++)
		{
			glm::ivec2 rayPosition = glm::ivec2(i, j);
			shared<Ray> ray = camera.CreateRay(rayPosition);
			glm::vec3 rayColour = tracer.TraceRay(ray);
			MCG::DrawPixel(rayPosition, rayColour);
		}
	}

	return MCG::ShowAndHold();
}