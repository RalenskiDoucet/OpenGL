#define GLM_FORCE_SWIZZLE 
#include "Mesh.h"

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ibo);
}

void Mesh::CreateBuffer()
{
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::StartUp()
{
	assert(vao == 0);
	Vertex vertices[6];
	vertices[0].position = { -0.5f, 0, 0.5f, 1 };
	vertices[1].position = { 0.5f, 0, 0.5f, 1 };
	vertices[2].position = { -0.5f, 0, -0.5f, 1 };
	vertices[3].position = { -0.5f, 0, -0.5f, 1 };
	vertices[4].position = { 0.5f, 0, 0.5f, 1 };
	vertices[5].position = { 0.5f, 0, -0.5f, 1 };

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE,
		sizeof(glm::vec4),(void*) 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), (void*)0);
	glBindVertexArray(0);
	tricount = 2;
	

}

void Mesh::draw()
{
	//glBindVertexArray(vao);
	
	glBindVertexArray(vao);
	glUseProgram(program);
	int variableID = glGetUniformLocation(program, "ProjectionViewWorld");;
	glm::mat4 mvp = projection * veiw*model;
	glUniformMatrix4fv(variableID, 1, GL_FALSE, &mvp[0][0]);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	if (ibo != 0)
		glDrawElements(GL_TRIANGLES, 3 * tricount,
			GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, 3 * tricount);
}

void Mesh::update()
{
	model = glm::mat4(1);
	glm::vec3 eye = glm::vec3(0, -10, -10);
	veiw = glm::lookAt(eye, model[3].xyz(), glm::vec3(0, 1, 0));
	projection = glm::perspective(glm::quarter_pi<float>(), 800 / (float)600, 0.1f, 1000.f);

}
