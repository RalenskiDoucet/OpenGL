#pragma once
#include <GLM/glm.hpp>

class Vertex
{
public:
	Vertex();
	Vertex(glm::vec4 pos, glm::vec4 clr);
	~Vertex();
	glm::vec4 position;
	glm::vec4 color;
};

