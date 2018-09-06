#pragma once
#include <Application.h>
#include "FlyCamera.h"

class IntroApplication : public Application
{
public:
	IntroApplication();
	~IntroApplication();
	glm::mat4 view = glm::lookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 10, 0));
	glm::mat4 projection = glm::perspective(glm::pi<float>() * 0.30f, 20 / 3.f, 0.15f, 1000.f);
	glm::mat4 model = glm::mat4(1);
	FlyCamera *mCamera = new FlyCamera;
protected:
	void startup() override;
	void shutdown() override;
	void update(float dt) override;
	void draw() override;
};