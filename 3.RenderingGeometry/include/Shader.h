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
	enum Light_Type {
		phong = 0,
	};
	void chooseLighting(Shader::Light_Type);
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
	const char* phongL;
	unsigned int m_program;
};


