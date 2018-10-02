#include "MeshRenderer.h"
#include "gl_core_4_4.h"
#include "Shader.h"

MeshRenderer::MeshRenderer() : vao(0), vbo(0), ibo(0) {}

MeshRenderer::~MeshRenderer()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ibo);
}
void MeshRenderer::initialise(std::vector<glm::vec4> positions)
{
}
void MeshRenderer::initialise(std::vector<glm::vec4> positions, std::vector<unsigned int> indices)
{
	std::vector<glm::vec4> points =
	{
		{glm::vec4(1,0,0,1)},
		{glm::vec4(0,1,0,0)},
		{glm::vec4(0,0,1,1)},
		{glm::vec4(-1,0,1,0)},
	};
	
}

void MeshRenderer::initialise()
{

	_vertices =
	{
		{ glm::vec4(-10, 10, 0, 1), glm::vec4(1, 0, 0, 1) },
		{ glm::vec4(10, 10, 0, 1), glm::vec4(0, 1, 0, 1) },
		{ glm::vec4(10, -10, 0, 1), glm::vec4(0, 0, 1, 1) },
		{ glm::vec4(-10, -10, 0, 1), glm::vec4(1, 1, 1, 1) },
	};
	_vertices[0].normal = { 0,1,0,0 };
	_vertices[1].normal = { 0,1,0,0 };
	_vertices[2].normal = { 0,1,0,0 };
	_vertices[3].normal = { 0,1,0,0 };
	_vertices[4].normal = { 0,1,0,0 };
	_vertices[5].normal = { 0,1,0,0 };
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)16);
	
	_indices = std::vector<unsigned int>{ 0,1,2,2,3,0 };

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex), _vertices.data(), GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), _indices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)sizeof(glm::vec4));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void MeshRenderer::draw()
{
	glBindVertexArray(vao);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLE_STRIP, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
