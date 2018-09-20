#include "Shader.h"
#include <stdio.h>
#include <cassert>
#include "gl_core_4_4.h"

namespace AIE
{

	Shader::~Shader() {
		glDeleteShader(m_handle);
	}

	void Shader::saveMethod(const char * cptr)
	{
		std::string src;
		FILE* stream;
		errno_t error = fopen_s(&stream, cptr, "r");
		char buf[500];
		while (std::fgets(buf, 500, stream))
			src.append(buf);
		const char* tmp = src.c_str();
		memcpy(&dest, &tmp, 500);
	}


	bool Shader::createShader(unsigned int stage, const char* string) {
		assert(stage > 0 && stage < eShaderStage::SHADER_STAGE_Count);

		m_stage = stage;

		switch (stage) {
		case eShaderStage::VERTEX:	m_handle = glCreateShader(GL_VERTEX_SHADER);	break;
		case eShaderStage::TESSELLATION_EVALUATION:	m_handle = glCreateShader(GL_TESS_EVALUATION_SHADER);	break;
		case eShaderStage::TESSELLATION_CONTROL:	m_handle = glCreateShader(GL_TESS_CONTROL_SHADER);	break;
		case eShaderStage::GEOMETRY:	m_handle = glCreateShader(GL_GEOMETRY_SHADER);	break;
		case eShaderStage::FRAGMENT:	m_handle = glCreateShader(GL_FRAGMENT_SHADER);	break;
		default:	break;
		};

		glShaderSource(m_handle, 1, (const char**)&string, 0);
		glCompileShader(m_handle);

		int success = GL_TRUE;
		glGetShaderiv(m_handle, GL_LINK_STATUS, &success);
		if (success == GL_FALSE) {
			int infoLogLength = 0;
			glGetShaderiv(m_handle, GL_INFO_LOG_LENGTH, &infoLogLength);

			delete[] m_lastError;
			m_lastError = new char[infoLogLength];
			glGetShaderInfoLog(m_handle, infoLogLength, 0, m_lastError);
			return false;
		}

		return true;
	}

	ShaderProgram::~ShaderProgram() {
		delete[] m_lastError;
		glDeleteProgram(m_program);
	}

	bool ShaderProgram::loadShader(unsigned int stage, const char* filename) {
		assert(stage > 0 && stage < eShaderStage::SHADER_STAGE_Count);
		m_shaders[stage] = std::make_shared<Shader>();
		return m_shaders[stage]->saveMethod(stage, filename);
	}

	bool ShaderProgram::createShader(unsigned int stage, const char* string) {
		assert(stage > 0 && stage < eShaderStage::SHADER_STAGE_Count);
		m_shaders[stage] = std::make_shared<Shader>();
		return m_shaders[stage]->createShader(stage, string);
	}

	void ShaderProgram::attachShader(const std::shared_ptr<Shader>& shader) {
		assert(shader != nullptr);
		m_shaders[shader->getStage()] = shader;
	}

	bool ShaderProgram::link() {
		m_program = glCreateProgram();
		for (auto& s : m_shaders)
			if (s != nullptr)
				glAttachShader(m_program, s->getHandle());
		glLinkProgram(m_program);

		int success = GL_TRUE;
		glGetProgramiv(m_program, GL_LINK_STATUS, &success);
		if (success == GL_FALSE) {
			int infoLogLength = 0;
			glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &infoLogLength);

			delete[] m_lastError;
			m_lastError = new char[infoLogLength + 1];
			glGetProgramInfoLog(m_program, infoLogLength, 0, m_lastError);
			return false;
		}
		return true;
	}

	void ShaderProgram::bind() {
		assert(m_program > 0 && "Invalid shader program");
		glUseProgram(m_program);
	}

	int ShaderProgram::getUniform(const char* name) {
		return glGetUniformLocation(m_program, name);
	}

}