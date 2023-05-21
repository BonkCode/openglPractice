#include "camera.h"
#include <iostream>
#include <stdio.h>

Camera::Camera(int width, int height, glm::vec3 _position)
{
    Camera::width = width;
    Camera::height = height;
    Camera::position = _position;
    Camera::mousePrevX = width / 2;
    Camera::mousePrevY = height / 2;
    Camera::yaw = -90.0f;
    Camera::pitch = 0.0f;
    Camera::roll = 0.0f;
}

void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(position, position + orientation, up);
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

	cameraMatrix = projection * view;
}

void Camera::Matrix(Shader& shader, const char* uniform)
{
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

void Camera::PollInputs(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        position += speed * orientation;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        position += speed * -glm::normalize(glm::cross(orientation, up));
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        position += speed * -orientation;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        position += speed * glm::normalize(glm::cross(orientation, up));
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        yaw   -= 1.0f;

        if(pitch > 89.0f)
            pitch = 89.0f;
        if(pitch < -89.0f)
            pitch = -89.0f;

        glm::vec3 direction;
        direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        direction.y = sin(glm::radians(pitch));
        direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        orientation = glm::normalize(direction);
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        yaw   += 1.0f;

        if(pitch > 89.0f)
            pitch = 89.0f;
        if(pitch < -89.0f)
            pitch = -89.0f;

        glm::vec3 direction;
        direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        direction.y = sin(glm::radians(pitch));
        direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        orientation = glm::normalize(direction);
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        position += speed * up;
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        position += speed * -up;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        speed = 0.1f;
    else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
        speed = 0.03f;

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

        double mouseX, mouseY;
        glfwGetCursorPos(window, &mouseX, &mouseY);

        if (firstClick)
        {
            mousePrevX = mouseX;
            mousePrevY = mouseY;
            firstClick = false;
        }
    
        float xoffset = mouseX - mousePrevX;
        float yoffset = mousePrevY - mouseY; 

        xoffset *= sensitivity;
        yoffset *= sensitivity;

        yaw   += xoffset;
        pitch += yoffset;

        if(pitch > 89.0f)
            pitch = 89.0f;
        if(pitch < -89.0f)
            pitch = -89.0f;

        glm::vec3 direction;
        direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        direction.y = sin(glm::radians(pitch));
        direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        orientation = glm::normalize(direction);
        //printf("%f:%f(%f-%f:%f-%f)\n", xoffset, yoffset, mouseX, mousePrevX, mouseY, mousePrevY);
        mousePrevX = mouseX;
        mousePrevY = mouseY;
    }
    else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
    { 
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        firstClick = true;
    }
}