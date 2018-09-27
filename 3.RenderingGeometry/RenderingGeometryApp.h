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
	std::vector <glm::vec3> CircleVerts =
	{ CircleVerts[1] = { 1, 0, 0 },
		CircleVerts[2] = { .50,.50,0 },
		CircleVerts[3] = { 1,1,0 },
		CircleVerts[4] = { -.50,50,0 },
		CircleVerts[5] = { -1,0,0 },
	};
	std::vector <glm::vec3> genHalfCircle(int np, double radius);
	std::vector<glm::vec3> genSphere(int np, int mer);
private:
	Shader *mShader;
	MeshRenderer* mMesh;
	Transform *mTransform;
	glm::mat4 model, view, projection;
};