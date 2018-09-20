#include "GLM\glm.hpp"
#include<vector>

class MeshRenderer
{
public:
	MeshRenderer();
	virtual ~MeshRenderer();
	void initialise(std::vector<glm::vec3> positions);
	struct Vertex
	{
		glm::vec4 position;
		glm::vec4 color;
	};

	std::vector<Vertex> _vertices;
	std::vector<unsigned int> _indices;

	//load vertex shader from file.
	void initialise();
	virtual void draw();
protected:	
	unsigned int vao, vbo, ibo;
};