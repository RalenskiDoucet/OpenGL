#pragma once
#include <GLM\glm.hpp>
#include <GLM\fwd.hpp>
#include <GLM\ext.hpp>
#include <Shader.h>
#include <MeshRenderer.h>
#include <Gizmos.h>

class Application3D
{
public:
	Application3D();
	virtual ~Application3D();
	virtual bool startup();
	virtual void shutdown();
	virtual void update(float deltaTime);
	virtual void draw();
protected:
	glm::mat4 m_veiwMatrix;
	glm::mat4 m_projectionMatrix;
	AIE::ShaderProgram m_shader;
	MeshRenderer m_quadMesh;
	glm::mat4 m_quadTransform;
};