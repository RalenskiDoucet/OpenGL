#pragma once
#include <GLM/glm.hpp>
#include <GLM/common.hpp>
#include<gl_core_4_4.h>
#include <gl/GL.h> 
#include <gl/GLU.h>
#include <vector>
#include <Application.h>
#include "RenderingGeometryApp.h"

class Mesh
{
public:

	Mesh() :tricount(0), vao(0),vbo(0),ibo(0){}
	virtual ~Mesh();
	struct Vertex 
	{
		glm::vec4 position;
		glm::vec4 normal;
		glm::vec2 texCoord;
	
	};
	unsigned int program;
	void CreateBuffer();
	void StartUp();

	virtual void draw();
	glm::mat4 model;
	glm::mat4 veiw;
	glm::mat4 projection;
	void update();
protected:
	unsigned int tricount;
	unsigned int vao, vbo, ibo;

};