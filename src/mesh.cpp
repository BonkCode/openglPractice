#include "mesh.h"

Mesh::Mesh(Prefab& prefab, Shader shader, Model model)
{
	Mesh::model = model;
	Mesh::prefab = prefab;
	Mesh::shader = shader;
 
	vao.Bind();
	VBO vbo(prefab.v_vertices);
	EBO ebo(prefab.v_indices);
	vao.LinkAttribute(vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	vao.LinkAttribute(vbo, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	vao.LinkAttribute(vbo, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
	vao.LinkAttribute(vbo, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float)));
	vao.Unbind();
	vbo.Unbind();
	ebo.Unbind();
}


void Mesh::Draw(Camera& camera)
{
	shader.Activate();
	vao.Bind();

	unsigned int numDiffuse = 0;
	unsigned int numSpecular = 0;

	for (unsigned int i = 0; i < prefab.v_textures.size(); i++)
	{
		std::string num;
		std::string type = prefab.v_textures[i].type;
		if (type == "diffuse")
		{
			num = std::to_string(numDiffuse++);
		}
		else if (type == "specular")
		{
			num = std::to_string(numSpecular++);
		}
		prefab.v_textures[i].TexUnit(shader, (type + num).c_str(), i);
		prefab.v_textures[i].Bind();
	}
	glUniform3f(glGetUniformLocation(shader.ID, "camPos"), camera.position.x, camera.position.y, camera.position.z);
	camera.Matrix(shader, "camMatrix");

	glDrawElements(GL_TRIANGLES, prefab.v_indices.size(), GL_UNSIGNED_INT, 0);
}