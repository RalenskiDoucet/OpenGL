#pragma once
#include "Application.h"
#include <GLM/common.hpp>
#include <GLM/fwd.hpp>

class MeshRenderer;
class Shader;
class DirectionalLight;
class Geometry;

class LightingApplication : public Application
{
public:
	LightingApplication();
	virtual ~LightingApplication();
	MeshRenderer* mesh;
	MeshRenderer* mesh2;
	MeshRenderer* lightSphere;
	Shader* mShader;
	Geometry* GEO;
	DirectionalLight* DirectLight;
	glm::mat4 model;
	glm::mat4 m_view;
	glm::mat4 m_projection;
	static void callback(GLFWwindow * window, int key, int scancode, int action, int mods);
protected:
	void startup() override;
	void shutdown() override;
	void update(float dt) override;
	void draw() override;

private:


};
