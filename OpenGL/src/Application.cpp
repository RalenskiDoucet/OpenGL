#include "Application.h"

Application::Application() :m_window(nullptr), m_gameover(false), m_clearColor{ 5,5,5,5 }, m_runningTime(0){}
Application::~Application()
{
}

void Application::run(const char * title, unsigned int width, unsigned int height, bool fullscreen)
{
	float prevTime = glfwGetTime();
	glfwInit();
	m_window = glfwCreateWindow(720, 720, "title", NULL, NULL);
	glfwMakeContextCurrent(m_window);
	ogl_LoadFunctions();
	auto minor = ogl_GetMinorVersion();
	auto major = ogl_GetMajorVersion();
	double PreviousTime = glfwGetTime();

	printf("GL: %i.%i\n", major, minor);

	glClearColor(0.15f, 0.15f, 0.15f, 1);
	glEnable(GL_DEPTH_TEST);
	startup();
	while (glfwWindowShouldClose(m_window) == false && glfwGetKey(m_window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		float currentTime = glfwGetTime();
		float deltaTime = currentTime - prevTime;
		prevTime = currentTime;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		update(deltaTime);
		double CurrentTime = glfwGetTime();
		double FrameDistance = PreviousTime - CurrentTime;
		draw();
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	
	}

	shutdown();
}

void Application::clearScreen()
{
}