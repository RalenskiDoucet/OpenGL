#include "IntroApplication.h"
int main()
{
	Application* app = new IntroApplication();
	app->run("introduction to opengl", 800, 600, false);
}