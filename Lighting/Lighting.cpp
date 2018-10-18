#include "Lighting.h"
#define GLM_FORCE_SWIZZLE
#include "Shader.h"
#include "RenderingGeometryApp.h"
#include "MeshRenderer.h"
#include "DirectionalLight.h"

#include "gl_core_4_4.h"
#include <GLFW/glfw3.h>
#include <vector>

float aC = 1;
float dC = 1;
float sC = 1;
float rt = 0;
glm::vec3 pos = glm::vec3(0);

LightingApplication::LightingApplication()
{
}


LightingApplication::~LightingApplication()
{
}

void LightingApplication::startup()
{
	mesh1;
	mesh2;
	Sphere = new MeshRenderer();
	baseShader = new Shader();
	directionalLight = new DirectionalLight();
	directionalLight->color = glm::vec4(0, .5, 0, 1);
	directionalLight->direction = glm::vec3(0, -1, 0);
	directionalLight->pos = glm::vec3(0, -1, 0);
	baseShader->load("shaders/d.vertex", Shader::SHADER_TYPE::VERTEX);
	baseShader->load("shaders/blin.fragment", Shader::SHADER_TYPE::FRAGMENT);
	baseShader->attach();

	int nm = 20;
	int np = 20;
	pos = glm::vec3(0, 0, 0);
	std::vector<glm::vec4> points = geom->genHalfCircle(np, 5);
	std::vector<glm::vec4> spherePoints = geom->genSphere(points, nm);
	std::vector<unsigned int> indices = geom->genSphereIndices(np, nm);
	std::vector<Vertex> vertices;
	std::vector<glm::vec2> daUV;
	float V = 0;
	for (int i = 0; i<2; i++)
	{
		for (int j = 0; j < spherePoints.size() / 2; j++)
		{
			daUV.push_back(glm::vec2((float)j / (spherePoints.size() / 2), V));
		}
		V++;
	}
	for (int i = 0; i < spherePoints.size(); i++)
	{
		vertices.push_back(Vertex(spherePoints[i], glm::vec4(1, 1, 1, 1), daUV[i]));
	}

	directionalLight->pos = glm::vec3(pos.x, pos.y, pos.z);
	directionalLight->direction = glm::vec3(0, -3, 0);
	glm::vec4 material = vertices[0].color;
	mesh1->initialize(indices, vertices);

}

void LightingApplication::update(float dt)
{
	rt += dt;
	glm::mat4 trans;
	float angle = glm::cos(rt*0.5f) * dt;
	glm::mat4 rot = glm::rotate(glm::mat4(1), glm::cos(dt), glm::vec3(0, 1, 0));
	trans = glm::translate(glm::mat4(1), glm::vec3(0, 0, 0));
	view = glm::lookAt(glm::vec3(0, -10, 20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	projection = glm::perspective(glm::quarter_pi<float>(), 800 / (float)600, 0.1f, 1000.f);
	model = glm::mat4(1) * rot;
	model = glm::mat4(1);
	if (glfwGetKey(m_window, GLFW_KEY_UP))
		pos.y += 0.1;
	if (glfwGetKey(m_window, GLFW_KEY_DOWN))
		pos.y -= 0.1;
	if (glfwGetKey(m_window, GLFW_KEY_RIGHT))
		pos.x += 0.1;
	if (glfwGetKey(m_window, GLFW_KEY_LEFT))
		pos.x -= 0.1;
	directionalLight->pos = glm::vec3(pos.x, pos.y, pos.z);
	glfwSetWindowUserPointer(m_window, this);
	glfwSetKeyCallback(m_window, key_callback);

}

void LightingApplication::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	LightingApplication* instance = (LightingApplication*)glfwGetWindowUserPointer(window);
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_1)
			aC == 1 ? aC = 0 : aC = 1;
		if (key == GLFW_KEY_2)
			dC == 1 ? dC = 0 : dC = 1;
		if (key == GLFW_KEY_3)
			sC == 1 ? sC = 0 : sC = 1;
	}
}

void LightingApplication::draw()
{
	baseShader->bind();
	int handle = baseShader->getUniform("ProjectionViewWorld");
	int lightColorHandle = baseShader->getUniform("lightColor");
	int lightPosHandle = baseShader->getUniform("lightPos");
	int lightDirHandle = baseShader->getUniform("lightDir");
	int CameraPosHandle = baseShader->getUniform("cameraPos");
	int ambientCoHandle = baseShader->getUniform("ambientCo");
	int diffuseCoHandle = baseShader->getUniform("diffuseCo");
	int specularCoHandle = baseShader->getUniform("specularCo");
	glm::mat4 mvp = projection * view * model;

	glUniformMatrix4fv(handle, 1, GL_FALSE, &mvp[0][0]);
	glm::vec3 col = directionalLight->color;
	glUniform3fv(lightColorHandle, 1, &col[0]);
	glUniform3fv(lightPosHandle, 1, &directionalLight->pos[0]);
	glUniform3fv(lightDirHandle, 1, &directionalLight->direction[0]);
	glm::vec3 view = glm::vec3(0, -10, 20);
	glUniform3fv(CameraPosHandle, 1, &view[0]);
	glUniform1fv(ambientCoHandle, 1, &aC);
	glUniform1fv(diffuseCoHandle, 1, &dC);
	glUniform1fv(specularCoHandle, 1, &sC);
	mesh1->render();
	mesh2->render();
	Sphere->render();
	baseShader->unbind();
}

void LightingApplication::shutdown()
{

}