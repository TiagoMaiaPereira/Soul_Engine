#include "Renderer.h"
#include "stb_image.h"
#include <iostream>
#include <sstream>
#include <fstream>


Renderer* Renderer::instance;
std::map<std::string, Texture> Renderer::Textures;
std::map<std::string, Shader>  Renderer::Shaders;

void Renderer::Render()
{

}

Shader Renderer::LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name)
{
    Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
    return Shaders[name];
}

Shader Renderer::loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile)
{
    
    std::cout << "vertex shader file path:" << vShaderFile << std::endl;

    std::cout << "fragment shader file path:" << fShaderFile << std::endl;

    std::string vertexCode;
    std::string fragmentCode;
    std::string geometryCode;
    try
    {

        std::ifstream vertexShaderFile(vShaderFile);
        std::ifstream fragmentShaderFile(fShaderFile);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vertexShaderFile.rdbuf();

        vertexShaderFile.seekg(0, std::ios::beg);

        fShaderStream << fragmentShaderFile.rdbuf();

        fragmentShaderFile.seekg(0, std::ios::beg);

        if (!vertexShaderFile.is_open()) { 
            std::cerr << "Failed to open vertex shader file!" << std::endl;
            // Handle the error
        }

        if (!fragmentShaderFile.is_open()) {
            std::cerr << "Failed to open fragment shader file!" << std::endl;
            // Handle the error
        }

        vertexShaderFile.close();
        fragmentShaderFile.close();

        vertexCode = vShaderStream.str();



        fragmentCode = fShaderStream.str();



        // if geometry shader path is present, also load a geometry shader
        if (gShaderFile != nullptr)
        {
            std::ifstream geometryShaderFile(gShaderFile);
            std::stringstream gShaderStream;
            gShaderStream << geometryShaderFile.rdbuf();
            geometryShaderFile.close();
            geometryCode = gShaderStream.str();
        }
    }
    catch (std::exception e)
    {
        std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();
    const char* gShaderCode = geometryCode.c_str();
    // 2. now create shader object from source code
    std::cout << vertexCode << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << fragmentCode << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;


    Shader shader;
    shader.Compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);
    return shader;
}


Shader Renderer::GetShader(std::string name)
{
    return Shaders[name];
}

Texture Renderer::LoadTexture(const char* file, bool alpha, std::string name)
{
    Textures[name] = loadTextureFromFile(file, alpha);
    return Textures[name];
}

Texture Renderer::GetTexture(std::string name)
{
    return Textures[name];
}

void Renderer::Clear()
{
    // (properly) delete all shaders	
    for (auto i : Shaders)
        glDeleteProgram(i.second.ID);
    // (properly) delete all textures
    for (auto i : Textures)
        glDeleteTextures(1, &i.second.ID);
}


Texture Renderer::loadTextureFromFile(const char* file, bool alpha)
{
    // create texture object
    Texture texture;
    if (alpha)
    {
        texture.Internal_Format = GL_RGBA;
        texture.Image_Format = GL_RGBA;
    }
    // load image
    int width, height, nrChannels;
    unsigned char* data = stbi_load(file, &width, &height, &nrChannels, 0);
    // now generate texture
    texture.Generate(width, height, data);
    // and finally free image data
    stbi_image_free(data);
    return texture;
}


