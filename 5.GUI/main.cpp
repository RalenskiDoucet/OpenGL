#include "GUIApplication.h"

int main()
{
	Application* app = new GUIApplication();
	app->run("title",720,800,false);
	
}