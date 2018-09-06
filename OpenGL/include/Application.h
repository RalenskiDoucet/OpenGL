#pragma once
#include <gl_core_4_4.h>
#include<glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/fwd.hpp>
#include <glfw3.h>
#include <Gizmos.h>
#include "stdio.h"
struct GLFWwindow;
class Application
{
	
public:
	Application();
	virtual ~Application();
	void clearScreen();
	void run(const char * title, unsigned int width, unsigned int height, bool fullscreen);

protected:
	
	GLFWwindow * m_window;
	virtual void startup() = 0;
	virtual void shutdown() = 0;
	virtual void update(float dt) = 0;
	virtual void draw() = 0;
	bool m_gameover;
	float m_clearColor[5];
	float m_runningTime;

};