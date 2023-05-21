#include "shader.h"

std::string get_file_contents(const char* filename)
{
    std::ifstream in(filename, std::ios::binary | std::ios::in);
    if (in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return(contents);
    }
    throw(errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
    std::string vertexCode = get_file_contents(vertexFile);
    std::string fragmentCode = get_file_contents(fragmentFile);

    const char* vertexSource = vertexCode.c_str();
    const char* fragmentSource = fragmentCode.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
    compileErrors(vertexShader, "VERTEX");

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
    compileErrors(fragmentShader, "FRAGMENT");

	ID = glCreateProgram();

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
    compileErrors(ID, "PROGRAM");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
    glUseProgram(ID);
}

void Shader::Delete()
{
    glDeleteProgram(ID);
}

void Shader::compileErrors(unsigned int shader, const std::string type)
{
    GLint hasCompiled;
    char infoLog[1024];

    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
        if (hasCompiled == GL_FALSE)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "SHADER_COMPLATION_ERROR for:" << type << "\n" << "log: " << infoLog << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_COMPILE_STATUS, &hasCompiled);
        if (hasCompiled == GL_FALSE)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << "log: " << infoLog << std::endl;
        }
    }
}

void Shader::SetUniforms(glm::vec4 lightColors[5], glm::vec3 lightPositions[5], glm::mat4 objectModel, int lightCount, int lightTypes[5])
{
    Activate();
	glUniformMatrix4fv(glGetUniformLocation(ID, "model"), 1, GL_FALSE, glm::value_ptr(objectModel));
	for (int i = 0; i < lightCount; i++)
	{
		char buff[100];
		snprintf(buff, sizeof(buff), "lightColors[%i]", i);
		glUniform4f(glGetUniformLocation(ID, buff), lightColors[i].x, lightColors[i].y, lightColors[i].z, lightColors[i].w);
		snprintf(buff, sizeof(buff), "lightPositions[%i]", i);
		glUniform3f(glGetUniformLocation(ID, buff), lightPositions[i].x, lightPositions[i].y, lightPositions[i].z);
		snprintf(buff, sizeof(buff), "lightTypes[%i]", i);
		glUniform1i(glGetUniformLocation(ID, buff), lightTypes[i]);
	}
	glUniform1i(glGetUniformLocation(ID, "lightsCount"), lightCount);
    glUniform4f(glGetUniformLocation(ID, "color"), 1.0f, 1.0f, 1.0f, 1.0f);
}

void Shader::SetUniforms(Light lights[5], glm::mat4 objectModel, int lightCount)
{
    Activate();
	glUniformMatrix4fv(glGetUniformLocation(ID, "model"), 1, GL_FALSE, glm::value_ptr(objectModel));
	for (int i = 0; i < lightCount; i++)
	{
		char buff[100];
		snprintf(buff, sizeof(buff), "lightColors[%i]", i);
		glUniform4f(glGetUniformLocation(ID, buff), lights[i].color.x, lights[i].color.y, lights[i].color.z, lights[i].color.w);
		snprintf(buff, sizeof(buff), "lightPositions[%i]", i);
		glUniform3f(glGetUniformLocation(ID, buff), lights[i].position.x, lights[i].position.y, lights[i].position.z);
		snprintf(buff, sizeof(buff), "lightTypes[%i]", i);
		glUniform1i(glGetUniformLocation(ID, buff), lights[i].type);
	}
	glUniform1i(glGetUniformLocation(ID, "lightsCount"), lightCount);
}

void Shader::SetUniforms(glm::mat4 objectModel, glm::vec4 lightColor)
{
    Activate();
    glUniformMatrix4fv(glGetUniformLocation(ID, "model"), 1, GL_FALSE, glm::value_ptr(objectModel));
	glUniform4f(glGetUniformLocation(ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
}

void Shader::ChangeColor(glm::vec4 color)
{
    Activate();
    glUniform4f(glGetUniformLocation(ID, "color"), color.x, color.y, color.z, color.w);
}