#include "GUIApplication.h"
#include "imgui.h"

GUIApplication::GUIApplication()
{
}

GUIApplication::~GUIApplication()
{
}

void GUIApplication::startup()
{
}

void GUIApplication::shutdown()
{
}

void GUIApplication::update(float dt)
{//use the model matrix to  move the square around
	
}

void GUIApplication::draw()
{
	if(ImGui::Button("Destroy the world")){}
}
