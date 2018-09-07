#include "FlyCamera.h"
#include <GLFW\glfw3.h> 
FlyCamera::FlyCamera()

{
	
	speed = 1;
	
}



FlyCamera::~FlyCamera()

{

}


void FlyCamera::update(float deltaTime)
{
	auto window = glfwGetCurrentContext();
	if (glfwGetKey(window, GLFW_KEY_W))

	{
		glm::vec3 prespective = glm::vec3(0, -speed * deltaTime, 0);

	}

	if (glfwGetKey(window, GLFW_KEY_A))

	{
		glm::vec3 prespective = glm::vec3(speed*deltaTime, 0, 0);

	}

	if (glfwGetKey(window, GLFW_KEY_S))
	{
		glm::vec3 prespective = glm::vec3(0, speed * deltaTime, 0);

	}

	if (glfwGetKey(window, GLFW_KEY_D))

	{
		glm::vec3 prespective= glm::vec3(-speed * deltaTime, 0, 0);

	}
}


void FlyCamera::setSpeed(float value)

{

	speed = value;

}
