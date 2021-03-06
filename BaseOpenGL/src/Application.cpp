#include "Application.h"
#include <gl_core_4_4.h>
#include <GLM\glm.hpp>
#include <GLM\ext.hpp>
#include <GLM\fwd.hpp>
#include <GLFW\glfw3.h>
#include <Gizmos.h>
#include "stdio.h"
#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"
Application::Application() :m_window(nullptr), m_gameover(false), m_clearColor{ 5,5,5,5 }, m_runningTime(0){}
Application::~Application()
{
}

void Application::run(const char * title, unsigned int width, unsigned int height, bool fullscreen)
{
	float prevTime = glfwGetTime();
	glfwInit();
	m_window = glfwCreateWindow(720, 720, "ChalkZone", NULL, NULL);
	glfwMakeContextCurrent(m_window);
	ogl_LoadFunctions();
	auto minor = ogl_GetMinorVersion();
	auto major = ogl_GetMajorVersion();
	double PreviousTime = glfwGetTime();

	printf("GL: %i.%i\n", major, minor);

	glClearColor(0.15f, 0.15f, 0.15f, 1);
	glEnable(GL_DEPTH_TEST);
	ImGui_ImplGlfwGL3_Init(m_window,true);
	
	startup();
	while (glfwWindowShouldClose(m_window) == false && glfwGetKey(m_window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		float currentTime = glfwGetTime();
		float deltaTime = currentTime - prevTime;
		prevTime = currentTime;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ImGui_ImplGlfwGL3_NewFrame();
		update(deltaTime);
		double CurrentTime = glfwGetTime();
		double FrameDistance = PreviousTime - CurrentTime;
		draw();
		ImGui::Render();
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	
	}

	shutdown();
}

void Application::clearScreen()
{
}