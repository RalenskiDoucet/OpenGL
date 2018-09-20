#define GLM_FORCE_SWIZZLE

#include "Shader.h"
#include <GLCORE/gl_core_4_4.h>
#include <fstream>
Shader::Shader()
{
	m_program = glCreateProgram();
}

Shader::~Shader()
{
}

void Shader::bind()
{
	glUseProgram(m_program);
}

void Shader::unbind()
{
	glUseProgram(0);
}

bool Shader::load(const char *Filename, Shader::SHADER_TYPE shadertype)
{
	errno_t err;
	FILE *file;
	err = fopen_s(&file, Filename, "r");
	char mstring[500];
	while(std::fgets(mstring, sizeof mstring, file))
	{
		if (shadertype == Shader::SHADER_TYPE::VERTEX)
		{
			vsSourceString.append(mstring);
		}
		else if (shadertype == Shader::SHADER_TYPE::FRAGMENT)
		{
			fsSourceString.append(mstring);
		}

	}
	vsSource = vsSourceString.c_str();
	fsSource = fsSourceString.c_str();
	return true;
}

bool Shader::attach()
{
	m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
	m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(m_vertexShader, 1, (const char**)&vsSource, 0);
	glCompileShader(m_vertexShader);
	glShaderSource(m_fragmentShader, 1, (const char**)&fsSource, 0);
	glCompileShader(m_fragmentShader);
	glAttachShader(m_program, m_vertexShader);
	glAttachShader(m_program, m_fragmentShader);
	glLinkProgram(m_program);
	return true;
}

void Shader::Load()
{
	vsSource = "#version 410\n \
                layout(location = 0) in vec4 Position; \
                layout(location = 1) in vec4 Color; \
                out vec4 vColor; \
                uniform mat4 ProjectionViewWorld; \
                void main() { vColor = Color; \
                gl_Position = ProjectionViewWorld * Position; }";

	fsSource = "#version 410\n \
                in vec4 vColor; \
                out vec4 FragColor; \
                void main() { FragColor = vColor; }";
}

unsigned int Shader::getUniform(const char *mvp)
{
	return glGetUniformLocation(m_program, mvp);;
}
