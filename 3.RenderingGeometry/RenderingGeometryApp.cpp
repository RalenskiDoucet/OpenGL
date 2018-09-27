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
	//1st two arguments int np(Number of Points); double radius;
	//2nd declare number of points;
	//3rd declare local varaible that will represent an vertex's position.

	std::vector <glm::vec3> circleVertices = {
	{ glm::vec3(-10,10,0),glm::vec3(1,0,0) },
	{ glm::vec3(10,10,0),glm::vec3(0,1,0) },
	{ glm::vec3(10,-10,0),glm::vec3(0,0,1) },
	{ glm::vec3(-10,-10,0),glm::vec3(1,0,0) },
	};

	for (int theta = 0; theta < 3.14; radius = 3.14;)
	{
		
	
		//calculate (angle or theta) in for loop.
		//angle is equals the answer of (3.14/number of points)
		theta= radius / np;
		//push back each vertice in the vertex _points->
		//that shows each generated portion of the half circle.
		circleVertices.push_back(theta);
		
	}
	return ;
}

std::vector<glm::vec4> RenderingGeometryApp::genSphere(int np, int mer)
{
	std::vector<glm::vec4> allPoints;
	int i;
	for(i<
}

