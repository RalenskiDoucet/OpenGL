#define GLM_FORCE_SWIZZLE
#include "RenderingGeometryApp.h"
#include <Vertex.h>

void RenderingGeometryApp::startup()
{
	int nm = 30;
	int np = 30;

	mMesh = new MeshRenderer();

	points=	genHalfCircle(np, nm);
	
	points = genSphere(points, nm);
	camera = new Camera();
	rotateHalfCircle(points, nm);

	std::vector<unsigned int> indices = genSphereIndices(np, 5);

	std::vector<MeshRenderer::Vertex> vertexs;
	for (glm::vec4 point : points)
	{
		MeshRenderer::Vertex vertex = { point, glm::vec4(150, 25, 50, 0) };
		vertexs.push_back(vertex);
	}
	mMesh->initialize(indices, vertexs);

	mShader = new Shader();

	mShader->load("vertex.vert", Shader::SHADER_TYPE::VERTEX);
	mShader->load("fragment.frag", Shader::SHADER_TYPE::FRAGMENT);

	mShader->attach();

}

//it happens inside of the rendering geometryapp  startup function every time after attach is Hit
void RenderingGeometryApp::shutdown()
{
}

void RenderingGeometryApp::update(float dt)
{
	model = glm::mat4(1);
	glm::vec3 eye = glm::vec3(10, -10, -10);
	view = glm::lookAt(eye, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	projection=camera->setPerspective(glm::pi<float>(), 800 / (float)600, .1f, 1000.f);
	view = camera->getView();


}

void RenderingGeometryApp::draw()
{
	glUseProgram(mShader->m_program);
	mShader->bind();
	glm::mat4 mvp = projection * view * model;
	mMesh->render();
	glUniformMatrix4fv(mShader->getUniform("ProjectionViewWorld"), 1, GL_FALSE, &mvp[0][0]);
	mShader->unbind();
	glUseProgram(0);
	
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

std::vector<unsigned int> RenderingGeometryApp::genSphereIndices(int np, int numofM)
{
	std::vector<unsigned int> Sphereindices;  
	unsigned int start;   
	unsigned int bottom_left;  
	unsigned int bottom_right;   
	for (int r = 0; r < numofM; r++) 
	{
		start = r * np; 
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
	
	Vertex A = Vertex(glm::vec4(-size, size, 0, 1), glm::vec4(1, 0, 0, 1), glm::vec2(0, 0));
	Vertex B = Vertex(glm::vec4(size, size, 0, 1), glm::vec4(1, 0, 0, 1), glm::vec2(1, 0));
	Vertex C = Vertex(glm::vec4(size, -size, 0, 1), glm::vec4(1, 0, 0, 1), glm::vec2(1, 1));
	Vertex D = Vertex(glm::vec4(-size, -size, 0, 1), glm::vec4(1, 0, 0, 1), glm::vec2(0, 1));
	std::vector<Vertex> PlaneVertices = { A,B,C,D };
	return PlaneVertices;
}

std::vector<Vertex> RenderingGeometryApp::genCube(std::vector<Vertex> vertices)
{
	//Front
	vertices.push_back(Vertex(glm::vec4(0, 1, 1, 1), glm::vec4(1), glm::vec2(0)));
	vertices.push_back(Vertex(glm::vec4(1, 1, 1, 1), glm::vec4(1), glm::vec2(0)));
	vertices.push_back(Vertex(glm::vec4(1, 0, 1, 1), glm::vec4(1), glm::vec2(0)));
	vertices.push_back(Vertex(glm::vec4(0, 0, 1, 1), glm::vec4(1), glm::vec2(0)));
   //Bottom																			  
	vertices.push_back(Vertex(glm::vec4(0, 0, 0, 1), glm::vec4(1), glm::vec2(0)));
	vertices.push_back(Vertex(glm::vec4(1, 0, 0, 1), glm::vec4(1), glm::vec2(0)));
    //Back
	vertices.push_back(Vertex(glm::vec4(1, 1, 0, 1), glm::vec4(1), glm::vec2(0)));
	vertices.push_back(Vertex(glm::vec4(0, 1, 0, 1), glm::vec4(1), glm::vec2(0)));
	//Top
	vertices.push_back(Vertex(glm::vec4(0, 1, 1, 1), glm::vec4(1), glm::vec2(0)));
	vertices.push_back(Vertex(glm::vec4(1, 1, 1, 1), glm::vec4(1), glm::vec2(0)));
	 //Right
	vertices.push_back(Vertex(glm::vec4(1, 1, 0, 1), glm::vec4(1), glm::vec2(0)));
	vertices.push_back(Vertex(glm::vec4(1, 0, 0, 1), glm::vec4(1), glm::vec2(0)));
	 //Left
	vertices.push_back(Vertex(glm::vec4(0, 1, 0, 1), glm::vec4(1), glm::vec2(0)));
	vertices.push_back(Vertex(glm::vec4(0, 0, 0, 1), glm::vec4(1), glm::vec2(0)));
	return vertices;
}

std::vector<glm::vec4> RenderingGeometryApp::rotateHalfCircle(std::vector<glm::vec4> points, unsigned int nm)
{
	std::vector<glm::vec4> allPoints;
	for (int i = 0; i <= nm; i++)
	{
		float slice = 2.0f * glm::pi<float>() / (float)nm;
		float theta = i * slice;
		for (int j = 0; j < points.size(); j++)
		{
			float newX = points[j].x;
			float newY = points[j].y * cos(theta) + points[j].z * -sin(theta);
			float newZ = points[j].z * cos(theta) + points[j].y * sin(theta);
			allPoints.push_back(glm::vec4(newX, newY, newZ, 1));
			//allPoints[i] = glm::round(allPoints[i]);
		}
	}
	return allPoints;
}

std::vector<unsigned int> RenderingGeometryApp::getCubeIndices()
{
	std::vector<unsigned int> indices =
	{ 0, 1, 2, 2, 3, 0,
		3, 2, 4, 4, 5, 2,
		4, 5, 6, 6, 7, 4,
		6, 7, 8, 8, 9, 6,
		2, 1, 10, 10, 11, 2,
		0, 3, 12, 12, 13, 0
	};
	return indices;
}

