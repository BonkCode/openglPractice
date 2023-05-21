#ifndef CAMERA_H
# define CAMERA_H

# include "glad.h"
# include <GLFW/glfw3.h>
# include "../glm/glm.hpp"
# include "../glm/gtc/matrix_transform.hpp"
# include "../glm/gtc/type_ptr.hpp"
# include "../glm/gtx/rotate_vector.hpp"
# include "../glm/gtx/vector_angle.hpp"
# include "shader.h"

class Camera
{
    public:
        float yaw, pitch, roll;
        glm::vec3 position;
        glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::mat4 cameraMatrix = glm::mat4(1.0f);

        bool firstClick = true;

        int width;
        int height;

        float speed = 0.03f;
        float sensitivity = 1.0f;

        Camera(int width, int height, glm::vec3 positoin);

        void updateMatrix(float FOVdeg, float nearPlane, float farPlane);
	    void Matrix(Shader& shader, const char* uniform);
        void PollInputs(GLFWwindow* window);
    private:
        float mousePrevX, mousePrevY;
};

#endif