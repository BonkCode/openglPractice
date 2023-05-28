#include "model.h"
#include <stdio.h>

Model::Model(glm::vec3 position, float scale)
{
    this->position = position;
	this->rotationDeg = 0.0f;
	this->rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
    model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::scale(model, glm::vec3(scale, scale, scale));
}

Model::Model(glm::vec3 position, float scale, float rotationDeg, glm::vec3 rotationAxis)
{
    this->position = position;
	this->rotationAxis = rotationAxis;
	this->rotationDeg = rotationDeg;
	model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::scale(model, glm::vec3(scale, scale, scale));
	model = glm::rotate(model, glm::radians(rotationDeg), rotationAxis);
}

void Model::Rotate(float angle, glm::vec3 axis)
{
	//printf("ROTATION START %f|", this->rotationDeg);
	model = glm::rotate(model, glm::radians(-rotationDeg), rotationAxis);
	model = glm::rotate(model, glm::radians(angle), axis);
	this->rotationAxis = axis;
	this->rotationDeg = angle;
	//printf("ROTATION END %f\n", this->rotationDeg);
}

void Model::Translate(glm::vec3 newPosition)
{
	printf("TRANSLATION START %f;%f;%f|", position.x, position.y, position.z);
	model = glm::rotate(model, glm::radians(-rotationDeg), rotationAxis);
	model = glm::translate(model, -this->position);
	model = glm::translate(model, newPosition);
	model = glm::rotate(model, glm::radians(rotationDeg), rotationAxis);
	this->position = newPosition;
	printf("TRANSLATION END %f;%f;%f\n", position.x, position.y, position.z);
}