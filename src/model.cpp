#include "model.h"

Model::Model(glm::vec3 position, float scale)
{
    Model::position = position;
    model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::scale(model, glm::vec3(scale, scale, scale));
}

Model::Model(glm::vec3 position, float scale, float rotationDeg, glm::vec3 rotationAxis)
{
    Model::position = position;
	model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::scale(model, glm::vec3(scale, scale, scale));
	model = glm::rotate(model, glm::radians(rotationDeg), rotationAxis);
}