#pragma once
#include <iostream>
#include <GLM/glm.hpp>

class Shader
{
public:
	Shader();
	~Shader();
	enum SHADER_TYPE {
		VERTEX = 0,
		FRAGMENT = 1
	};
	std::string fsSourceString;
	std::string vsSourceString;
	std::string data;
	void bind();
	void unbind();
	bool load(const char* filename, Shader::SHADER_TYPE);
	bool attach();
	void Load();

	unsigned int getUniform(const char* mvp);
	unsigned int m_vertexShader;
	unsigned int m_fragmentShader;

	const char* vsSource;
	const char* fsSource;

	unsigned int m_program;
};

struct ShaderData
{
	Shader* shader;
	char* source;
	unsigned type;
	bool CorrectFile;
};
