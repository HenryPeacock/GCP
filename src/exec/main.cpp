#include <ParallelRayTracer/ParallelRayTracer.h>

#include <cmath>
#include <iostream>
#include <time.h>
#include <thread>
#include <mutex>
#include <chrono>


// Mutex
std::mutex mtx;

// Thread function
void PixelThread(glm::ivec2 _rayPosition, Camera _camera, RayTracer _tracer, float _rowSize)
{
	for (int j = 0; j < _rowSize; j++)
	{
		_rayPosition.y = j;
		shared<Ray> ray = _camera.CreateRay(_rayPosition);
		glm::vec4 rayColour = _tracer.TraceRay(ray);
		mtx.lock();
		MCG::DrawPixel(_rayPosition, rayColour);
		mtx.unlock();
	}
}

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	// Ctrl + F "ToDo"

	srand(time(NULL));
	float windowX = 1920.0f;
	float windowY = 1080.0f;
	// Storage variables
	glm::ivec2 windowSize(windowX, windowY);
	glm::ivec4 pixelColour = glm::ivec4(255.0f, 0.0f, 0.0f,0.0f);

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
	//MCG::DrawPixel(pixelPosition, pixelColour);

	// Make the variables
	Camera camera(windowSize);
	RayTracer tracer;
	// Make Spheres
	shared<Sphere> sphere = makesh<Sphere>();
	sphere->SetPosition(glm::vec3(1.0f, 0.0f, 7.0f));
	sphere->SetRadius(1.0f);
	sphere->SetColour(glm::vec4(255.0f, 0.0f, 0.0f, 255.0f));
	sphere->SetAmbient(0.01f);
	shared<Sphere> sphere2 = makesh<Sphere>();
	sphere2->SetPosition(glm::vec3(0.0f, 0.0f, 6.0f));
	sphere2->SetRadius(1.0f);
	sphere2->SetColour(glm::vec4(0.0f, 255.0f, 0.0f, 255.0f));
	sphere2->SetAmbient(0.01f);
	shared<Sphere> sphere3 = makesh<Sphere>();
	sphere3->SetPosition(glm::vec3(0.0f, 1.0f, 6.5f));
	sphere3->SetRadius(1.0f);
	sphere3->SetColour(glm::vec4(0.0f, 0.0f, 255.0f, 255.0f));
	sphere3->SetAmbient(0.01f);
	shared<Sphere> sphere4 = makesh<Sphere>();
	sphere4->SetPosition(glm::vec3(1.0f, 0.0f, 7.5f));
	sphere4->SetRadius(1.0f);
	sphere4->SetColour(glm::vec4(255.0f, 255.0f, 0.0f, 255.0f));
	sphere4->SetAmbient(0.01f);
	shared<Sphere> sphere5 = makesh<Sphere>();
	sphere5->SetPosition(glm::vec3(0.0f, -1.0f, 7.5f));
	sphere5->SetRadius(1.0f);
	sphere5->SetColour(glm::vec4(255.0f, 0.0f, 0.0f, 255.0f));
	sphere5->SetAmbient(0.01f);
	shared<Sphere> sphere6 = makesh<Sphere>();
	sphere6->SetPosition(glm::vec3(0.0f, 2.0f, 7.5f));
	sphere6->SetRadius(1.0f);
	sphere6->SetColour(glm::vec4(0.0f, 255.0f, 0.0f, 255.0f));
	sphere6->SetAmbient(0.01f);
	shared<Sphere> sphere7 = makesh<Sphere>();
	sphere7->SetPosition(glm::vec3(0.0f, -2.0f, 7.5f));
	sphere7->SetRadius(1.0f);
	sphere7->SetColour(glm::vec4(0.0f, 0.0f, 255.0f, 255.0f));
	sphere7->SetAmbient(0.01f);
	shared<Sphere> sphere8 = makesh<Sphere>();
	sphere8->SetPosition(glm::vec3(0.0f, -2.0f, 7.5f));
	sphere8->SetRadius(1.0f);
	sphere8->SetColour(glm::vec4(0.0f, 0.0f, 255.0f, 255.0f));
	sphere8->SetAmbient(0.01f);
	shared<Sphere> sphere9 = makesh<Sphere>();
	sphere9->SetPosition(glm::vec3(0.0f, -2.0f, 7.5f));
	sphere9->SetRadius(1.0f);
	sphere9->SetColour(glm::vec4(0.0f, 0.0f, 255.0f, 255.0f));
	sphere9->SetAmbient(0.01f);
	// Add Spheres
	tracer.AddSphere(sphere);
	tracer.AddSphere(sphere2);
	tracer.AddSphere(sphere3);
	tracer.AddSphere(sphere4);
	tracer.AddSphere(sphere5);
	tracer.AddSphere(sphere6);
	tracer.AddSphere(sphere7);
	tracer.AddSphere(sphere8);
	tracer.AddSphere(sphere9);
	// Make Light
	shared<Light> light = makesh<Light>(
		glm::vec3(1.0f, 1.0f, -2.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec4(255.0f, 255.0f, 255.0f, 255.0f));
	// Add Light
	tracer.AddLight(light);
	// Threads

	int menuChoice = 0;
	while (menuChoice != 1 && menuChoice != 2)
	{
		std::cout << "Threads or no threads? (1 = threads, 2 = no threads) ";
		std::cin >> menuChoice;
		// Pray?
		if (menuChoice == 1)
		{
			// https://www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--
			start = std::chrono::high_resolution_clock::now();
			//
			for (int i = 0; i < windowSize.x / 4; i++)
			{
				int k = i * 4;
				std::thread thread1(PixelThread, glm::ivec2(k, k), camera, tracer, windowSize.y);
				std::thread thread2(PixelThread, glm::ivec2(k + 1, k), camera, tracer, windowSize.y);
				std::thread thread3(PixelThread, glm::ivec2(k + 2, k), camera, tracer, windowSize.y);
				std::thread thread4(PixelThread, glm::ivec2(k + 3, k), camera, tracer, windowSize.y);

				thread1.join();
				thread2.join();
				thread3.join();
				thread4.join();
			}
		}
		else if (menuChoice == 2)
		{
			// https://www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--
			start = std::chrono::high_resolution_clock::now();
			//
			for (int i = 0; i < windowSize.x; i++)
			{
				for (int j = 0; j < windowSize.y; j++)
				{
					glm::ivec2 rayPosition = glm::ivec2(i, j);
					shared<Ray> ray = camera.CreateRay(rayPosition);
					glm::vec4 rayColour = tracer.TraceRay(ray);
					MCG::DrawPixel(rayPosition, rayColour);
				}
			}
		}
	}

	// https://www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "Elapsed time: " << elapsed.count() << "s\n";
	//
	return MCG::ShowAndHold();
}

