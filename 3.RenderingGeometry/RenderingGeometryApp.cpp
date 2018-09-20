#include "RenderingGeometryApp.h"
#include "Shader.h"
#include "MeshRenderer.h"
#include "GLM/ext.hpp"
#include "gl_core_4_4.h"

void RenderingGeometryApp::startup()
{
	model = glm::mat4(1);
	view = glm::lookAt(glm::vec3(0, -10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	projection = glm::perspective(glm::quarter_pi<float>(), 16 / (float)9, 0.1f, 1000.0f);

	mShader = new Shader();
	mShader->load("vertex.vert", Shader::SHADER_TYPE::VERTEX);
	mShader->load("fragment.frag", Shader::SHADER_TYPE::FRAGMENT);
	mShader->attach();
	mMesh = new MeshRenderer();
	mMesh->initialise();
	
}

void RenderingGeometryApp::shutdown()
{
}

void RenderingGeometryApp::update(float dt)
{
	
	
}

void RenderingGeometryApp::draw()
{
	mShader->bind();
	glm::mat4 mvp = projection * view * model;
	glUniformMatrix4fv(mShader->getUniform("ProjectionViewWorld"), 1, GL_FALSE, &mvp[0][0]);
	
	mMesh->draw();
	mShader->unbind();
	genHalfCircle();
	

}

void RenderingGeometryApp::genHalfCircle(int np,int radius)
{
	np = 5;
	int Points[] = { (1,0),(7.7),(0,1),(-7,7),(-1,0) };
	radius = 3.14 / np;
	for (int theta = 0; theta < 3.14; theta = 3.14/np)
	{

	}
}
