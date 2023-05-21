#ifndef PREFAB_H
# define PREFAB_H

# include "VBO.h"
# include "texture.h"

class Prefab
{
    public:
        std::vector <Vertex> get_vertices();
        std::vector <GLuint> get_indices();

        std::vector <Vertex> v_vertices;
        std::vector <GLuint> v_indices;
        std::vector <Texture> v_textures;

        Texture* textures;
		Vertex* vertices;
		GLuint* indices;

        Prefab() = default;
        Prefab(Vertex vertices[], GLuint indices[], Texture textures[], int vertLen, int indLen, int texLen);
};

#endif