#include "IntroApplication.h"
#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"
#include "Camera.h"
#include "FlyCamera.h"
#include "Gizmos.h"
#include <GLM/glm.hpp>
#include <GLM/ext.hpp>


IntroApplication::IntroApplication()
{
}

IntroApplication::~IntroApplication()
{
}


void IntroApplication::startup()
{
	Gizmos::create();
	mCamera = new FlyCamera();
	mCamera->setLookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	mCamera->setPerspective(glm::pi<float>()*0.25f, 16 / 9.0f, 0.1f, 1000.0f);	
	mCamera->setSpeed(10);

}


void IntroApplication::update(float dt)
{
	mCamera->update(dt);
}

void IntroApplication::shutdown()
{
	Gizmos::destroy();
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void IntroApplication::draw()
{	
	Gizmos::clear();
	Gizmos::addTransform(glm::mat4(1));
	glm::vec4 white(1);
	glm::vec4 black(0, 0, 0, 1);
	for (int i = 0; i < 21; ++i) {
		Gizmos::addLine(glm::vec3(-10 + i, 0, 10),
			glm::vec3(-10 + i, 0, -10),
			i == 10 ? white : black);
		Gizmos::addLine(glm::vec3(10, 0, -10 + i),
			glm::vec3(-10, 0, -10 + i),
			i == 10 ? white : black);
	}
	Gizmos::addSphere(glm::vec3(0, 0, 0), 5, 15, 10, glm::vec4(1, 1, 1, 1), &model);
	Gizmos::draw(mCamera->getProjection() * mCamera->getView() * mCamera->getWorldTransform());

}
