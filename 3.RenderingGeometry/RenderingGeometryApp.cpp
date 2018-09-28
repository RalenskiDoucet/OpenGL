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
	std::vector<glm::vec4>CircleVerts;
	
	for (float i=0;i<np;i++)
	{
		//calculate (angle or theta) in for loop.
		//angle is equals the answer of (3.14/number of points)
		float angle = glm::pi<float>() / ((float) np - 1);
		float theta = i * angle;
	
		//push back each vertice in the vertex _points->
		//that shows each generated portion of the half circle
		CircleVerts.push_back(glm::vec4(glm::cos(theta)*radius, glm::sin(theta)*radius, 0, 1));
		
	}
	return CircleVerts;
	
}

std::vector<glm::vec4> RenderingGeometryApp::genSphere(std::vector<glm::vec4>points, unsigned int numofM)
{

	std::vector<glm::vec4> SpherePoints;   
	for (int i = 0; i < numofM + 1; i++) 
	{
		float sphereSlice = (glm::pi<float>() * 2) / (float)numofM; 
		float theta = i * sphereSlice;  
		for (int j = 0; j < points.size(); j++) 
		{ 
			float X = points[j].x;  
			float Y = points[j].y * cos(theta) + points[j].z * -sin(theta);        
			float Z = points[j].z * cos(theta) + points[j].y * sin(theta);      
			glm::vec4 point = glm::vec4(X, Y, Z, 1); 
			SpherePoints.push_back(point);
		} 
	}   
	return SpherePoints;

}

std::vector<unsigned int> RenderingGeometryApp::genSphereIndices(unsigned int np, unsigned int numM)
{
	std::vector<unsigned int> Sphereindices;  
	unsigned int start;   
	unsigned int bottom_left;  
	unsigned int bottom_right;   
	for (int r = 0; r < numM; r++) 
	{
		start = y * np; 
		for (int p = 0; p < np; p++) 
		{
			bottom_left = start + p;
			bottom_right = bottom_left + np;
			Sphereindices.push_back(bottom_left);
			Sphereindices.push_back(bottom_right); 
		}     
		Sphereindices.push_back(0xFFFF);
	} 
	return Sphereindices;

}

std::vector<Vertex> RenderingGeometryApp::genPlane(int size)
{
	Vertex A = Vertex(glm::vec4(-size, size, 0, 1), glm::vec4(1, 0, 0, 1));  
	Vertex B = Vertex(glm::vec4(size, size, 0, 1), glm::vec4(1, 0, 0, 1));
	Vertex C = Vertex(glm::vec4(size, -size, 0, 1), glm::vec4(1, 0, 0, 1)); 
	Vertex D = Vertex(glm::vec4(-size, -size, 0, 1), glm::vec4(1, 0, 0, 1));  
	std::vector<Vertex> PlaneVertices = { A,B,C,D };   
	return PlaneVertices;
}

std::vector<Vertex> RenderingGeometryApp::genCube(std::vector<Vertex> vertices)
{
	std::vector<Vertex> CubePoints;    
	 
	CubePoints.push_back(Vertex(glm::vec4(0, 1, 1, 1),glm::vec4(1)));
	CubePoints.push_back(Vertex(glm::vec4(1, 1, 1, 1), glm::vec4(1)));
	CubePoints.push_back(Vertex(glm::vec4(1, 0, 1, 1), glm::vec4(1)));
	CubePoints.push_back(Vertex(glm::vec4(0, 0, 1, 1), glm::vec4(1)));   
	CubePoints.push_back(Vertex(glm::vec4(0, 0, 0, 1), glm::vec4(1))); 
	CubePoints.push_back(Vertex(glm::vec4(1, 0, 0, 1), glm::vec4(1))); 
	CubePoints.push_back(Vertex(glm::vec4(1, 1, 0, 1), glm::vec4(1)));
	CubePoints.push_back(Vertex(glm::vec4(0, 1, 0, 1), glm::vec4(1)));   
	CubePoints.push_back(Vertex(glm::vec4(0, 1, 1, 1), glm::vec4(1)));
	CubePoints.push_back(Vertex(glm::vec4(1, 1, 1, 1), glm::vec4(1)));  
	CubePoints.push_back(Vertex(glm::vec4(1, 1, 0, 1), glm::vec4(1)));
	CubePoints.push_back(Vertex(glm::vec4(1, 0, 0, 1), glm::vec4(1)));
	CubePoints.push_back(Vertex(glm::vec4(0, 1, 0, 1), glm::vec4(1)));
	CubePoints.push_back(Vertex(glm::vec4(0, 0, 0, 1), glm::vec4(1)));
	return CubePoints;
}

