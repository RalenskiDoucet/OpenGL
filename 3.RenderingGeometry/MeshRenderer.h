#include "GLM\glm.hpp"
#include<vector>

class MeshRenderer
{
public:
	MeshRenderer();
	virtual ~MeshRenderer();
	struct Vertex
	{
		glm::vec4 position;
		glm::vec4 color;
		glm::vec4 normal;
		glm::vec2 textCoord;
	};
	
	void initialize(std::vector<unsigned int>& m_indices, std::vector<Vertex>& m_vertices);
	void render();

	std::vector<unsigned int> m_indices;
	std::vector<Vertex> m_vertices;

	unsigned int vao;
	unsigned int vbo;
	unsigned int ibo;

	void create_Buffers();
};