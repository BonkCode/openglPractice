#include "prefab.h"

Prefab::Prefab(Vertex vertices[], GLuint indices[], Texture textures[], int vertLen, int indLen, int texLen)
{
    v_vertices = std::vector<Vertex>(vertices, vertices + vertLen);
    v_indices = std::vector<GLuint>(indices, indices + indLen);
    v_textures = std::vector<Texture>(textures, textures + texLen);
}

std::vector <Vertex> Prefab::get_vertices()
{
    return(this->v_vertices);
}

std::vector <GLuint> Prefab::get_indices()
{
    return(this->v_indices);
}