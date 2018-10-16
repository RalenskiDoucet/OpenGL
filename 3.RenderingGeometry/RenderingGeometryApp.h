#pragma once
#define GLM_FORCE_SWIZZLE
#include "Shader.h"
#include "MeshRenderer.h"
#include <Transform.h>
#include <Vertex.h>
#include <Camera.h>
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
	Vertex *vertices;
	std::vector<glm::vec4>points;
	std::vector <glm::vec4> genHalfCircle(int np, double radius);
	std::vector<glm::vec4> genSphere(std::vector<glm::vec4>points, unsigned int numofM);
	std::vector<unsigned int>genSphereIndices(int np, int numofM);
	std::vector<Vertex> genPlane(int size);
	std::vector<Vertex>genCube(std::vector<Vertex> vertices);
	std::vector<glm::vec4> rotateHalfCircle(std::vector<glm::vec4>points, unsigned int nm);
	std::vector<unsigned int> getCubeIndices();
	Shader *mShader;
	MeshRenderer* mMesh;
	Camera *camera;
	
	Transform *mTransform= new Transform();
	glm::mat4 model, view, projection;
};