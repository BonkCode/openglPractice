#ifndef VAO_H
# define VAO_H

# include "glad.h"
# include "VBO.h"

class VAO
{
    public:
        GLuint ID;
        VAO();

        void LinkAttribute(VBO& _VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
        void Bind();
        void Unbind();
        void Delete();
};

#endif