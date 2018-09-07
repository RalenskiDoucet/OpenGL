#include "Camera.h"
#include <GLM\glm.hpp>
#include <GLM\fwd.hpp>
#include <GLM\ext.hpp>
#include <iostream>
Camera::Camera()
{
	worldTransform = glm::mat4(1);	
}

Camera::~Camera()
{
}
void Camera::update(float Deltatime)
{
}
void Camera::setPerspective(float feildofveiw, float aspectRatio, float near, float far)
{
	
	projectionTransform = glm::perspective(feildofveiw, aspectRatio, near, far);
}
void Camera::setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up)
{
	viewTransform = glm::lookAt(from, to, up);
}


void Camera::setPosition(glm::vec3 position) 
{
	worldTransform[2].x += position[0];
	worldTransform[2].y += position[1]; 
	worldTransform[2].z += position[2];    
	std::cout << worldTransform[2].x << " , " << worldTransform[2].y << " , " << worldTransform[2].z << std::endl;
	
} 
glm::mat4 Camera::getWorldTransform() 
{
	return worldTransform; 
} 
glm::mat4 Camera::getView() 
{
	return viewTransform; 
}

glm::mat4 Camera::getProjection()
{
	return projectionTransform;
}
glm::mat4 Camera::getProjectionView() 
{ 
	return projectionViewTransform; 
}

void Camera::ChangeProjection(int isActive)
{
}



void Camera::updateProjectionViewTransform()
{
}
