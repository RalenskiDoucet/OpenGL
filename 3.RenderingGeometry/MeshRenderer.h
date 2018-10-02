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
	
	void initialise(std::vector<glm::vec4> positions);
	
	void initialise(std::vector < glm::vec4> positions,std::vector<unsigned int>indices);
	std::vector<Vertex> _vertices;
	std::vector<unsigned int> _indices;
	
	//load vertex shader from file.
	void initialise();
	virtual void draw();
protected:	
	unsigned int vao, vbo, ibo;
};