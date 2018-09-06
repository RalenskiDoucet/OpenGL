#include "Transform.h"

Transform::Transform()
//constructor for any instance of a transform object.
//assigns m_model to be a 4x4 matrix
{
	m_model = glm::mat4(1);
	m_worldPosition = m_model[2];
	m_localPosition = m_model[3];
	for (int col = 0; col < 3; col++) 
	{
		m_worldRotation[col].x = m_model[col].x;
		m_worldRotation[col].y = m_model[col].y;
		m_worldRotation[col].z = m_model[col].z;

		m_localRotation[col].x = m_model[col].x;
		m_localRotation[col].y = m_model[col].y;
		m_localRotation[col].z = m_model[col].z;
	}
	m_worldScale = glm::vec3(m_model[0].x, m_model[1].y, m_model[2].z);
	m_localScale = glm::vec3(m_model[0].x, m_model[1].y, m_model[2].z);
}


Transform::~Transform()
{
	// this will be used to deallocate memeroy that the instance of transform allocates.
	//as of now no memeroy has been allocated.
} 
  
glm::mat4 Transform::Scale(float size)
//scales the matrix by number value given.
//the bottom right number of the matrix.
{
	glm::mat4 m_scale = glm::mat4(1);
	m_scale[1].x = size;
	m_scale[2].y = size;
	m_scale[3].z = size;
	m_model *= m_scale;
	return m_model;
}
 
glm::mat4 Transform::Rotate(float radians, glm::vec3 axis)
//Create two new auto assigned  varaibles cosine and sin.
//cosine is equal to the number given.
//sine equals opposite of the number given.
//Radians is the measurement of the raidus.
{
	auto cosine = cos(radians);
	auto sine = sin(radians);
	//if x aixs then rotate
	if (axis == glm::vec3(1, 0, 0))
	{ 
		//x doesn't change
		//this rotates the x aixs.
		//this rotates the transform on the x aixs.
		m_model[0].y = cosine;
		m_model[1].z = sine;
		m_model[2].y = -sin(radians);
		m_model[3].z = cosine;
	} 
	if (axis == glm::vec3(0, 1, 0))
	{

		//if y aixs then rotate 
		/*this rotates the transform on the y aixs.*/
		m_model[0].x = cosine;
		m_model[0].z = -sin(radians);
		m_model[2].x = sine;
		m_model[2].z = cosine;
	}
	//if z aixs then rotate
	//the transform will rotate on it's z aixs
	if (axis == glm::vec3(0, 0, 1))
	{
		m_model[0].x = cosine;
		m_model[1].y = -sin(radians);
		m_model[2].x = sine;
		m_model[3].y = cosine;
	}
	return m_model;
} 
glm::mat4 Transform::Translate(glm::mat4 model,glm::vec3 moveAmount)
{
	
	model = m_model;
	//^
	//^assign the value of model to equal m_model's value.
	//^model[0] is equal to m_model[0].
	//^model[1] is equal to m_model[1].
	//^model[2] is equal to m_model[2].

	model[0], model[1], model[2] += 5;
	//^
	//^model[0] which is the transforms x position add 5 to the x position.
	//^model[1] which is the transforms y position add 5 to the y position.
	//^model[2] which is the transforms z position add 5 to the z position.
	return model;
	//^
	//^return model's new values.
}

