#pragma once
#include <iostream>
#include <map>
#include <string>
#include "Texture.h"
#include "glad/glad.h"
#include "Shader.h"


class Renderer
{
public:
	void Render();
    Renderer() {}
	static Renderer& getRenderer(){return *instance;}
	//--------------------------------------------------------------------------------------------------

    static std::map<std::string, Shader>    Shaders;
    static std::map<std::string, Texture> Textures;
    
    static Shader LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name);

    static Shader GetShader(std::string name);

    static Texture LoadTexture(const char* file, bool alpha, std::string name);

    static Texture GetTexture(std::string name);

    static void Clear();

private:
	static Renderer* instance;
    
    
    static Texture loadTextureFromFile(const char* file, bool alpha);

    static Shader loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = nullptr);

};

