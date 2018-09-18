#include "RenderingGeometryApp.h"

void RenderingGeometryApp::startup()
{
	mesh.initialise();
}

void RenderingGeometryApp::shutdown()
{
}

void RenderingGeometryApp::update(float dt)
{
}

void RenderingGeometryApp::draw()
{
	mesh.draw();
}
