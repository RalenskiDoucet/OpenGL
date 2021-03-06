#pragma once
class Shader
{
public:
	Shader();
	~Shader();
	void bind();
	void unbind();
	bool load(const char* filename, unsigned int type, bool isFile = true);
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
