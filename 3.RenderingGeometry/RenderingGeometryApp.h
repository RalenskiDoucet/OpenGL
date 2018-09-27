#pragma once
#include "Shader.h"
#include "MeshRenderer.h"
#include <Transform.h>
#include <Vertex.h>
#include "GLM/ext.hpp"
#include "gl_core_4_4.h"
#include <Application.h>
#include <GLM/glm.hpp>
class Shader;//forward declare this to use in the RenderingGeometryApp.cpp
class MeshRenderer;//forward declare this to use in the RenderingGeometryApp.cpp

class RenderingGeometryApp : public Application
{
public:
	void startup() override;
	void shutdown() override;
	void update(float dt) override;
	void draw() override;
	
	std::vector <glm::vec4> genHalfCircle(int np, double radius);
	std::vector<glm::vec4> genSphere(int np, int mer);
private:
	Shader *mShader;
	MeshRenderer* mMesh;
	Transform *mTransform;
	glm::mat4 model, view, projection;
};