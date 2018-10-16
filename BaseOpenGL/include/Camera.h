#pragma once
#include "GLM\glm.hpp"

class Camera
{
public:
	Camera() ;
	~Camera(); 
	void update(float Deltatime); 
	glm::mat4 setPerspective(float fieldofview, float aspectRatio, float near, float far);
	void setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up);
	void setPosition(glm::vec3 position); 
	glm::mat4 getWorldTransform(); 
	glm::mat4 getView(); 
	glm::mat4 getProjection();
	glm::mat4 getProjectionView();
	void ChangeProjection(int isActive);
	void setOrthographicView(float right, float left, float top, float bottom, float far, float near);
	void setPerspectiveView(float fov, float aspectRatio, float near, float far);
private:   
	
	glm::mat4 worldTransform;  
	glm::mat4 viewTransform;  
	glm::mat4 projectionTransform; 
	glm::mat4 projectionViewTransform;
	void updateProjectionViewTransform();};

