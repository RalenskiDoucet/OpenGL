#include "Application3D.h"
#define SET_BACKGROUND_COLOR

Application3D::Application3D()
{
}

Application3D::~Application3D()
{
}

bool Application3D::startup()
{
	SET_BACKGROUND_COLOR(0.25f, 0.25f, 0.25f);
	Gizmos::create(10000, 10000, 10000);
	m_veiwMatrix = glm::lookAt(vec3(10), vec3(0), vec3(0), vec3(0, 1, 0));
	m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f,
		getWindowWidth() / (float)getWindowHeight(),
		0.1f, 1000.f);
	m_shader.loadShader(AIE::eShaderStage::VERTEX,
		"./shaders/simple.vert");
	m_shader.loadShader(AIE::eShaderStage::FRAGMENT,
		"./shaders/simple.frag");
	if (m_shader.link() == false) {
		printf("Shader Error: %s\n", m_shader.getLastError());
		return false;
	}
	m_quadMesh.initialise();
	m_quadTransform = {
		10,0,0,0,
		0,10,0,0,
		0,0,10,0,
		0,0,0,1 };

}

void Application3D::shutdown()
{
}

void Application3D::update(float deltaTime)
{
}

void Application3D::draw()
{


	m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f,
		getWindowWidth() / (float)getWindowHeight(),
		0.1f, 1000.f);
	m_shader.bind();
	auto pvm = m_projectionMatrix * m_viewMatrix * m_quadTransform;
	m_shader.bindUniform("ProjectionViewModel", pvm);
	
	m_quad.draw();
	Gizmos::draw(m_projectionMatrix * m_viewMatrix);
	Gizmos::draw2D((float)getWindowWidth(), (float)getWindowHeight());
}
