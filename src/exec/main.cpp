#include <ParallelRayTracer/ParallelRayTracer.h>

#include <cmath>
#include <iostream>
#include <time.h>

int main()
{
	srand(time(NULL));
	float windowX = 640.0f;
	float windowY = 480.0f;
	// Storage variables
	glm::ivec2 windowSize(windowX, windowY);
	glm::ivec3 pixelColour = glm::ivec3(255.0f, 0.0f, 0.0f);

	// Initialise the window
	if (!MCG::Init(windowSize))
	{
		return -1;
	}

	// Sets all pxels to a colour
	MCG::SetBackground(glm::ivec3(0.0f, 0.0f, 0.0f));

	// Determine where the pixel should be
	glm::ivec2 pixelPosition = windowSize / 2;

	// Draw the single pixel
	MCG::DrawPixel(pixelPosition, pixelColour);

	return MCG::ShowAndHold();
}