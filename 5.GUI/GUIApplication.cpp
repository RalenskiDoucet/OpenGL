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
	if(ImGui::Button("Move Left")){}
	if (ImGui::Button("Move Right")) {}
	if (ImGui::Button("Move Up")) {}
	if (ImGui::Button("Move Down")) {}
	if (ImGui::Button("Move Left")) {}
	

}
