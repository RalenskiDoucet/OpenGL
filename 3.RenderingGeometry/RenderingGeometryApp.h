#pragma once
#define GLM_FORCE_SWIZZLE
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
	std::vector<glm::vec4> genSphere(std::vector<glm::vec4>points, unsigned int numofM);
	std::vector<unsigned int>genSphereIndices(unsigned int np, unsigned int numM);
	std::vector<Vertex> genPlane(int size);
	std::vector<Vertex>genCube(std::vector<Vertex> vertices)
private:
	Shader *mShader;
	MeshRenderer* mMesh;
	Transform *mTransform;
	glm::mat4 model, view, projection;
};