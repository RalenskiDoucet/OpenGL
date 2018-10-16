#include "Camera.h"
#include <GLM\glm.hpp>
#include <GLM\fwd.hpp>
#include <GLM\ext.hpp>
#include <iostream>
Camera::Camera() : projectionTransform(glm::mat4(1))
{
	worldTransform = glm::mat4(1);	
}

Camera::~Camera()
{
}
void Camera::update(float Deltatime)
{
}
glm::mat4 Camera::setPerspective(float fieldofview, float aspectRatio, float near, float far)
{
	projectionTransform[0].x = 1 / aspectRatio * tan(fieldofview / 2);
	projectionTransform[1].y = 1 / tan(fieldofview / 2);
	projectionTransform[2].z = 1 / -((far + near) / (far - near));
	projectionTransform[2].w = -1;
	projectionTransform[3].z = ((2 * far *near)/(far - near));
	return projectionTransform;
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

void Camera::setOrthographicView(float right, float left, float top, float bottom, float far, float near)
{
	projectionTransform[0].x = 2 / (right - left);
	projectionTransform[1].y = 2 / (top - bottom);
	projectionTransform[2].z = -2 / (far - near);
	projectionTransform[3].x = -((right + left) / (right - left));
	projectionTransform[3].y = -((top + bottom) / (top - bottom));
	projectionTransform[3].z = -((far + near) / (far - near));
}

void Camera::setPerspectiveView(float fov, float aspectRatio, float far, float near)
{
	projectionTransform[0].x = 1 / (aspectRatio * tan(fov / 2));
	projectionTransform[1].y = 1 / tan(fov / 2);
	projectionTransform[2].z = -((far + near) / (far - near));
	projectionTransform[2].w = -1;
	projectionTransform[3].z = -((2 * far*near) / (far - near));
}



void Camera::updateProjectionViewTransform()
{
	projectionViewTransform = projectionTransform * viewTransform;
}
