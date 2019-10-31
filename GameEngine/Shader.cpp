#include "Shader.h"

using namespace std;

Shader::Shader(const char * vertexPath, const char* fragmentPath){
	// coger los vertex / fragement source code form file
	string vertexCode;
	string fragmentCode;
	ifstream vShaderFile;
	ifstream fShaderFile;
	stringstream vShaderStream;
	stringstream fShaderStream;

	vShaderFile.open(vertexPath);
	fShaderFile.open(fragmentPath);

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{

		if (!vShaderFile.is_open() || !fShaderFile.is_open()) {
			throw exception("openfile error");
		}
		// read file buffe content into stream
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();

	}
	catch (const std::exception& e )
	{
		printf(e.what());
	}

	const char * vShaderCode = vertexCode.c_str();
	const char * fShaderCode = fragmentCode.c_str();

	//compile shader
	unsigned int vertex, fragment;
	//vertexShader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	//fragmeent shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);

	//shader program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	//delete the shader as there linekd into our program no not necessary
	glDeleteShader(vertex);
	glDeleteShader(fragment);

}

void Shader::use() {
	glUseProgram(ID);
}
/*Shader::~Shader()
{
}*/
