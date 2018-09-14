#pragma once
#include <Application.h>
#include <Shader.h>
#include <MeshRenderer.h>
#include <Gizmos.h>


class Application3D:public Application 
{
public:
	Application3D();
	virtual ~Application3D();
	virtual void startup();
	virtual void shutdown();
	virtual void update(float deltaTime);
	virtual void draw();
protected:
	AIE::ShaderProgram m_shader;
	MeshRenderer m_quadMesh;
};