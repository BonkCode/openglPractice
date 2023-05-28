#include "scene.h"
#include <math.h>
#include <iostream>

const unsigned int window_width = 800;
const unsigned int window_height = 800;

Vertex planeVertices[] =
{ //               COORDINATES           /            NORMALS          /           COLORS         /       TEXTURE COORDINATES    //
	Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3( 1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3( 1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
};

Vertex redPlaneVertices[] =
{ //               COORDINATES           /            NORMALS          /           COLORS         /       TEXTURE COORDINATES    //
	Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.1f, 0.1f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.1f, 0.1f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3( 1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.1f, 0.1f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3( 1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.1f, 0.1f), glm::vec2(1.0f, 0.0f)}
};

Vertex bluePlaneVertices[] =
{ //               COORDINATES           /            NORMALS          /           COLORS         /       TEXTURE COORDINATES    //
	Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3( 1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3( 1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 1.0f), glm::vec2(1.0f, 0.0f)}
};


Vertex cubeVertices[] =
{
	Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(1.0f, -1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(1.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)}
};

Vertex cube24Vertices[] =
{
	Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(1.0f, -1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(1.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
	// -----
	Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(1.0f, -1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(1.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	// ------
	Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(1.0f, -1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(1.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
};


Vertex longCubeVertices[] =
{
	Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(0.1f, 0.1f, 0.75f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(0.1f, 0.1f, 0.75f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(1.0f, -1.0f, 1.0f), glm::vec3(0.1f, 0.1f, 0.75f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec3(0.1f, 0.1f, 0.75f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f, 1.5f, -0.5f), glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(0.1f, 0.1f, 0.75f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, 1.5f, -0.5f), glm::vec3(1.0f, 1.0f, -1.0f), glm::vec3(0.1f, 0.1f, 0.75f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(0.5f, 1.5f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.1f, 0.1f, 0.75f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-0.5f, 1.5f, 0.5f), glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec3(0.1f, 0.1f, 0.75f), glm::vec2(1.0f, 1.0f)}
};

GLuint cubeIndices[] =
{
	0, 1, 3,
	1, 2, 3,
	1, 2, 5,
	5, 6, 2,
	6, 2, 3,
	6, 3, 7,
	7, 3, 0,
	7, 0, 4,
	4, 0, 1,
	4, 1, 5,
	4, 5, 6,
	4, 6, 7
};

GLuint cube24Indices[] =
{
	0, 1, 3,
	1, 2, 3,
	1, 2, 5,
	5, 6, 2,
	6, 2, 3,
	6, 3, 7,
	7, 3, 0,
	7, 0, 4,
	4, 0, 1,
	4, 1, 5,
	4, 5, 6,
	4, 6, 7,
	// ---
	0, 1, 3,
	1, 2, 3,
	1, 2, 5,
	5, 6, 2,
	6, 2, 3,
	6, 3, 7,
	7, 3, 0,
	7, 0, 4,
	4, 0, 1,
	4, 1, 5,
	4, 5, 6,
	4, 6, 7,
	// ---
	0, 1, 3,
	1, 2, 3,
	1, 2, 5,
	5, 6, 2,
	6, 2, 3,
	6, 3, 7,
	7, 3, 0,
	7, 0, 4,
	4, 0, 1,
	4, 1, 5,
	4, 5, 6,
	4, 6, 7
};

GLuint longCubeIndices[] =
{
	0, 1, 3,
	1, 2, 3,
	1, 2, 5,
	5, 6, 2,
	6, 2, 3,
	6, 3, 7,
	7, 3, 0,
	7, 0, 4,
	4, 0, 1,
	4, 1, 5,
	4, 5, 6,
	4, 6, 7
};

GLuint planeIndices[] =
{
	0, 1, 2,
	0, 2, 3
};

int main(void)
{
	for (int i = 24; i < 48; i++)
	{
		cube24Indices[i] += 8;
	}
	for (int i = 48; i < 72; i++)
	{
		cube24Indices[i] += 16;
	}
	GLFWwindow* window;

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if (!(window = glfwCreateWindow(window_width, window_height, "qwe", NULL, NULL)))
	{
		std::cout << "Failed to create a window" << std::endl;
		glfwTerminate();
		return (-1);
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();

	glViewport(0, 0, window_width, window_height);

	Texture woodTextures[]
	{
		Texture("src/Textures/planks.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture("src/Textures/planksSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	Texture popcatTextures[]
	{
		Texture("src/Textures/pop_cat.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE)
	};

	Texture defaultTexture[]
	{
		Texture("src/Textures/default.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE)
	};

	Prefab cube24Prefab = Prefab(cube24Vertices, cube24Indices, popcatTextures, sizeof(cube24Vertices) / sizeof(Vertex), sizeof(cube24Indices) / sizeof(GLuint), sizeof(popcatTextures) / sizeof(Texture));
	Prefab woodenPlanePrefab = Prefab(planeVertices, planeIndices, woodTextures, sizeof(planeVertices) / sizeof(Vertex), sizeof(planeIndices) / sizeof(GLuint), sizeof(woodTextures) / sizeof(Texture));
	Prefab cubePrefab = Prefab(cubeVertices, cubeIndices, popcatTextures, sizeof(cubeVertices) / sizeof(Vertex), sizeof(cubeIndices) / sizeof(GLuint), sizeof(popcatTextures) / sizeof(Texture));
	Prefab longCubePrefab = Prefab(longCubeVertices, longCubeIndices, defaultTexture, sizeof(longCubeVertices) / sizeof(Vertex), sizeof(longCubeIndices) / sizeof(GLuint), sizeof(defaultTexture) / sizeof(Texture));
	Prefab redWallPrefab = Prefab(redPlaneVertices, planeIndices, defaultTexture, sizeof(redPlaneVertices) / sizeof(Vertex), sizeof(planeIndices) / sizeof(GLuint), sizeof(defaultTexture) / sizeof(Texture));
	Prefab blueWallPrefab = Prefab(bluePlaneVertices, planeIndices, defaultTexture, sizeof(bluePlaneVertices) / sizeof(Vertex), sizeof(planeIndices) / sizeof(GLuint), sizeof(defaultTexture) / sizeof(Texture));
	Prefab lightPrefab = Prefab(cubeVertices, cubeIndices, defaultTexture, sizeof(cubeVertices) / sizeof(Vertex), sizeof(cubeIndices) / sizeof(GLuint), sizeof(defaultTexture) / sizeof(Texture));

	Model blueLightModel(glm::vec3(0.0f, 2.05f, 0.0f), 0.2f);
	Model redLightModel(glm::vec3(-0.25f, 2.05f, 0.0f), 0.2f);
	Model greenLightModel(glm::vec3(0.25f, 2.05f, 0.0f), 0.2f);
	Model floorModel(glm::vec3(0.0f, 0.0f, 0.0f), 1.0f);
	Model cubeModel(glm::vec3(0.25f, 0.25f, 0.25f), 0.5f, 25.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	Model longCubeModel(glm::vec3(0.0f, 0.24f, -0.5f), 0.5f, 25.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	Model roofModel(glm::vec3(0.0f, 2.0f, 0.0f), 1.0f);
	Model leftWallModel(glm::vec3(-1.0f, 1.0f, 0.0f), 1.0f, 90.0f, glm::vec3(0.0f, 0.0f, 1.0f));
	Model rightWallModel(glm::vec3(1.0f, 1.0f, 0.0f), 1.0f, 90.0f, glm::vec3(0.0f, 0.0f, 1.0f));
	Model backWallModel(glm::vec3(0.0f, 1.0f, -1.0f), 1.0f, 90.0f, glm::vec3(1.0f, 0.0f, 0.0f));

	Mesh cube(cubePrefab, Shader("src/Shaders/default.vert", "src/Shaders/default.frag"), cubeModel);
	Mesh roof(woodenPlanePrefab, Shader("src/Shaders/default.vert", "src/Shaders/default.frag"), roofModel);
	Mesh leftWall(redWallPrefab, Shader("src/Shaders/default.vert", "src/Shaders/default.frag"), leftWallModel);
	Mesh rightWall(blueWallPrefab, Shader("src/Shaders/default.vert", "src/Shaders/default.frag"), rightWallModel);
	Mesh backWall(woodenPlanePrefab, Shader("src/Shaders/default.vert", "src/Shaders/default.frag"), backWallModel);
	Mesh floor(woodenPlanePrefab, Shader("src/Shaders/default.vert", "src/Shaders/default.frag"), floorModel);
	Mesh longCube(longCubePrefab, Shader("src/Shaders/default.vert", "src/Shaders/default.frag"), longCubeModel);
	Mesh blueLight(lightPrefab, Shader("src/Shaders/light.vert", "src/Shaders/light.frag"), blueLightModel);
	Mesh redLight(lightPrefab, Shader("src/Shaders/light.vert", "src/Shaders/light.frag"), redLightModel	);
	Mesh greenLight(lightPrefab, Shader("src/Shaders/light.vert", "src/Shaders/light.frag"), greenLightModel);

	Mesh objects[] =
	{
		cube,
		roof,
		leftWall,
		rightWall,
		backWall,
		floor,
		longCube,
		blueLight,
		redLight,
		greenLight
	};

	int objectCount = sizeof(objects) / sizeof(Mesh);

	glm::vec4 redLightColor = glm::vec4(1.0f, 0.1f, 0.1f, 1.0f);
	glm::vec4 blueLightColor = glm::vec4(0.1f, 0.1f, 1.0f, 1.0f);
	glm::vec4 greenLightColor = glm::vec4(0.1f, 1.0f, 0.1f, 1.0f);

	Light lights[] =
	{
		Light(redLightModel.position, redLightColor, L_POINT),
		Light(greenLightModel.position, greenLightColor, L_POINT),
		Light(blueLightModel.position, blueLightColor, L_POINT)
	};

	int lightCount = sizeof(lights) / sizeof(Light);

	blueLight.shader.SetUniforms(blueLightModel.model, blueLightColor);
	redLight.shader.SetUniforms(redLightModel.model, redLightColor);
	greenLight.shader.SetUniforms(greenLightModel.model, greenLightColor);

	floor.shader.SetUniforms(lights, floorModel.model, lightCount);
	cube.shader.SetUniforms(lights, cubeModel.model, lightCount);
	longCube.shader.SetUniforms(lights, longCubeModel.model, lightCount);
	roof.shader.SetUniforms(lights, roofModel.model, lightCount);
	leftWall.shader.SetUniforms(lights, leftWallModel.model, lightCount);
	rightWall.shader.SetUniforms(lights, rightWallModel.model, lightCount);
	backWall.shader.SetUniforms(lights, backWallModel.model, lightCount);

	glEnable(GL_DEPTH_TEST);

	Camera camera(window_width, window_height, glm::vec3(0.0f, 1.0f, 4.0f));

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	io.ConfigFlags = ImGuiConfigFlags_NavEnableKeyboard;
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	Mesh *target = &cube;
	float newPos[] = {0.0f, 0.0f, 0.0f};
	float newRotation = 0.0f;
	float rotationAxis[] = {0.0f, 0.0f, 0.0f};
	int targetID = 0;
	int prevID = 0;

	const char *object_names[] = 
	{
		"Cube",
		"roof",
		"left wall", 
		"right wall",
		"back wall",
		"floor",
		"long cube",
		"blue light",
		"red light",
		"green light"
	};

	target = &(objects[targetID]);
	newRotation = target->model.rotationDeg;
	for (int i = 0; i < 3; i++)
		newPos[i] = target->model.position[i];
	for (int i = 0; i < 3; i++)
		rotationAxis[i] = target->model.rotationAxis[i];
	//newPos = {target->model.position.x, target->model.position.y, target->model.position.z};
	//rotationAxis = {target->model.rotationAxis.x, target->model.rotationAxis.y, target->model.rotationAxis.z};

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		if (!io.WantCaptureMouse && !io.WantCaptureKeyboard)
			camera.PollInputs(window);
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		//cube.shader.Activate();
		//cubeModel.model = glm::rotate(cubeModel.model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(glGetUniformLocation(cube.shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(cubeModel.model));
		

		for(int i = 0; i < objectCount; i++)
			objects[i].Draw(camera);

		ImGui::Begin("window");
		ImGui::Combo("Id", &targetID, object_names, IM_ARRAYSIZE(object_names));

		target = &(objects[targetID]);
		//newRotation = target->model.rotationDeg;
		//newPos = glm::value_ptr(target->model.position);
		//rotationAxis = glm::value_ptr(target->model.rotationAxis);

		ImGui::SliderFloat("Rotation", &newRotation, 0.0f, 360.0f);
		ImGui::SliderFloat3("Axis", rotationAxis, 0.0f, 1.0f);
		ImGui::SliderFloat3("Position", newPos, -2.0f, 2.0f);
		ImGui::End();

		if (targetID != prevID)
		{
			prevID = targetID;
			newRotation = target->model.rotationDeg;
			for (int i = 0; i < 3; i++)
				newPos[i] = target->model.position[i];
			for (int i = 0; i < 3; i++)
				rotationAxis[i] = target->model.rotationAxis[i];
			//newPos = {target->model.position.x, target->model.position.y, target->model.position.z};
			//rotationAxis = {target->model.rotationAxis.x, target->model.rotationAxis.y, target->model.rotationAxis.z};
			
		}
		else
		{
			target->shader.Activate();
			target->model.Translate(glm::make_vec3(newPos));
			target->model.Rotate(newRotation, glm::make_vec3(rotationAxis));
		
			//target->model.model = glm::translate(glm::vec3(newPos[0], newPos[1], newPos[2]));
			//target->model.model = glm::rotate(target->model.model, glm::radians(newRotation), glm::vec3(rotationAxis[0], rotationAxis[1], rotationAxis[2]));
			glUniformMatrix4fv(glGetUniformLocation(target->shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(target->model.model));
		}

		//recolortarget->shader.ChangeColor(glm::vec4(newColor[0] / 255, newColor[1] / 255, newColor[2] / 255, newColor[3] / 255));

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	for(int i = 0; i < objectCount; i++)
		objects[i].shader.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return (0);
}

