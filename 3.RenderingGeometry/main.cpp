#include "RenderingGeometryApp.h"
int main()
{
	Application* app = new RenderingGeometryApp();
	app->run("title", 720, 800, false);
	MeshRenderer* render;
	render->initialise();
	render->draw();

}