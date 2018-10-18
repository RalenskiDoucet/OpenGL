#pragma once
#include <Application.h>
#include <GLM/common.hpp>
#include <GLM/fwd.hpp>

class MeshRenderer;
class Shader;
class DirectionalLight;
class Geometry;

typedef void(*KeyFunc)(GLFWwindow *window, int key, int scancode, int action, int mods);

class LightingApplication : public Application
{
public:
	LightingApplication();
	virtual ~LightingApplication();
	MeshRenderer* mesh;
	MeshRenderer* mesh2;
	MeshRenderer* lightSphere;
	Shader* defaultShader;
	RenderingGeometryApp* geom;
	DirectionalLight* DaLight;
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
protected:
	void startup() override;
	void shutdown() override;
	void update(float dt) override;
	void draw() override;

private:


};

