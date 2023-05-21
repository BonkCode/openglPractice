#ifndef MESH_H
# define MESH_H

# include<string>

# include "VAO.h"
# include "EBO.h"
# include "camera.h"
# include "texture.h"
# include "shader.h"
# include "prefab.h"
# include "model.h"

class Mesh
{
public:
	Shader shader;
	Prefab prefab;
	Model model;
	VAO vao;

	Mesh(Prefab& prefab, Shader shader, Model model);

	void Draw(Camera& camera);
};

#endif