#pragma once

#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include <fstream>
#include <sstream>  

class Shader
{
public:

	
	unsigned int ID;
	Shader(const char * vertexPath, const char* fragmentPath);
	//~Shader();
	void use();

private :
	void checkCompileErrors(unsigned int ID, std::string type);
};

