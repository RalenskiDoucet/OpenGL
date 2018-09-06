#pragma once
#include <GLM/glm.hpp>
#include <GLM/common.hpp>
#include<gl_core_4_4.h>
#include <gl/GL.h> 
#include <gl/GLU.h>
#include <vector>
#include <Application.h>
#include "RenderingGeometryApp.h"
#include "Mesh.h"
class Shader
{
	void run();
	unsigned int program;
};