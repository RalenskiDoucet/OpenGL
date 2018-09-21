#define GLM_FORCE_SWIZZLE
#include "RenderingGeometryApp.h"


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
	genHalfCircle(5,180);
	

}

std::vector<glm::vec4> RenderingGeometryApp::genHalfCircle(int np, double radius)
{
	
	//np=number of points.
	//radius=3.14.

	int angle = 3.14 / np;
	std::vector <glm::vec4>points;
	int i = 0;
	for (int theta = 0; theta < 3.14; theta += angle)
	{
		points.push_back(glm::vec4(cos(theta), sin(theta), 0, 1));
		i++;
	}
	return points;
}

void RenderingGeometryApp::genSphere(int np, int mer)
{

}
