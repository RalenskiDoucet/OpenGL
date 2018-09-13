#include "MeshRenderer.h"
#include <assert.h>
MeshRenderer::~MeshRenderer()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ibo);
}

void MeshRenderer::LinkShader()
{
	shader.loadShader(AIE::eShaderStage::VERTEX,
		"./shaders/simple.vert");
	shader.loadShader(AIE::eShaderStage::FRAGMENT,
		"./shaders/simple.frag");
	if (shader.link() == false)
	{
		printf("Shader ERROR: %s\n", shader.getLastError());
		Vertex Shader(simple.vert)
	}


}


void MeshRenderer::initialise()
{
	unsigned int vertexCount
		unsigned int vertexCount; const Vertex* vertices;
		unsigned int indexCount = 0;
		unsigned int* indices = nullptr;
	assert(vao == 0);
	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	vertex vertices[6];
	vertices[0].position={ -0.5f,0,0.5f,1 };
	vertices[1].position={ 0.5f,0,0.5f,1 };
	vertices[2].position={ -0.5f,0,-0.5f,1 };
	vertices[3].position={ -0.5f,0,-0.5f,1 };
	vertices[4].position={ 0.5f,0,0.5f,1 };
	vertices[5].position={ -0.5f,0,0-.5f,1 };
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(vertex), vertices,
		GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 
		sizeof(vertex), 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	tricount = 2;

}

void MeshRenderer::draw()
{
	glBindVertexArray(vao);
	if (ibo != 0)
		glDrawElements(GL_TRIANGLES, 3 *
			tricount, GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, 3 * tricount);

}
