#ifndef SHADER_H
# define SHADER_H

# include "glad.h"
# include <string>
# include <fstream>
# include <sstream>
# include <iostream>
# include <cerrno>
# include "../glm/glm.hpp"
# include "../glm/gtc/type_ptr.hpp"
# include "light.h"

std::string get_file_contents(const char* filename);

class Shader
{
    public:
        GLuint ID;
        
        Shader(const char* vertexFile, const char* fragmentFile);
        Shader() = default;

        void Activate();
        void Delete();
        void SetUniforms(Light lightss[5], glm::mat4 objectModel, int lightCount);
        void SetUniforms(glm::vec4 lightColors[5], glm::vec3 lightPositions[5], glm::mat4 objectModel,  int lightCount, int lightTypes[5]);
        void SetUniforms(glm::mat4 objectModel, glm::vec4 lightColor);
        void ChangeColor(glm::vec4 color);
    private:
        void compileErrors(unsigned int shader, const std::string type);
};

#endif