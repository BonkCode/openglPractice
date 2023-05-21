#ifndef TEXTURE_H
# define TEXTURE_H

# include "glad.h"
# include "stb_image.h"
# include "shader.h"

class Texture
{
    public:
        GLuint ID;
        const char* type;
        GLuint unit;

        Texture(const char* image, const char* texType, GLuint slot, GLenum format, GLenum pixelType);

        void TexUnit(Shader shader, const char * uniform, GLuint unit);
        void Bind();
        void Unbind();
        void Delete();
};

#endif