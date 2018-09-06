#pragma once
#include <GLM/glm.hpp> 

class Camera
{
public:
	Camera() ;
	~Camera(); 
	void update(float Deltatime); 
	void setPerspective(float feildofveiw, float aspectRatio, float near, float far);
	void setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up);
	void setPosition(glm::vec3 position); 
	glm::mat4 getWorldTransform(); 
	glm::mat4 getView(); 
	glm::mat4 getProjection();
	glm::mat4 getProjectionView();
	auto ChangeProjection(int isActive);
private:   
	glm::mat4 worldTransform;  
	glm::mat4 viewTransform;  
	glm::mat4 projectionTransform; 
	glm::mat4 projectionViewTransform;
	void updateProjectionViewTransform();};

