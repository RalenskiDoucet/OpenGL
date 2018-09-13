#include "GLM\glm.hpp"
#include "gl_core_4_4.h"
#include <Shader.h>


class MeshRenderer
{
public:
	MeshRenderer() :tricount(0),vao(0),vbo(0),ibo(0){}
	virtual ~MeshRenderer();
	struct vertex
	{
		glm::vec4 position;
		glm::vec4 normal;
		glm::vec2 texcoord;
	};
	AIE::ShaderProgram shader;
	void LinkShader();
	//load vertex shader from file.
	void initialise();
	virtual void draw();
protected:
	unsigned int tricount;
	unsigned int vao, vbo, ibo;
};