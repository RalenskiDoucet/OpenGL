#pragma once
#include "Application.h"
#define GLM_FORCE_SWIZZLE

class Transform
{
public:
	Transform();
	~Transform();

	glm::mat4 Translate(glm::mat4 model,glm::vec3 moveAmount);
	glm::mat4 Rotate(float radians, glm::vec3 axis);
	glm::mat4 Scale(float size);
private:
	/* 
	xyzw 
	1000 
	0100 
	0010 
	0001 
	*/ 
	glm::mat4 m_model; //The identity matrix.
 
	glm::vec3 m_worldPosition; // equal to the last column's values
	glm::vec3 m_localPosition; //
	 
	glm::mat3 m_worldRotation; // 3x3 matrix that takes in the top left values of the identity matrix
	glm::mat3 m_localRotation; //
	 
	glm::vec3 m_worldScale; // Takes in the diagonal values of the matrix
	glm::vec3 m_localScale; //
	 
	 
}; 

