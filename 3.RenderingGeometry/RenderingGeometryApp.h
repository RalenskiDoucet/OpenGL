#pragma once
#include <Application.h>
#include <MeshRenderer.h>
class RenderingGeometryApp:public Application
{
public:
	MeshRenderer mesh;
	void startup() override;
	void shutdown() override;
	void update(float dt) override;
	void draw() override;
};