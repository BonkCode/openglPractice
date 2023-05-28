#ifndef MODEL_H
# define MODEL_H

# include "../glm/glm.hpp"
# include "../glm/gtc/matrix_transform.hpp"

class Model
{
    public:
        Model() = default;
        glm::vec3 rotationAxis;
        float rotationDeg;
        glm::vec3 position;
        glm::mat4 model;
        Model(glm::vec3 position, float scale);
        Model(glm::vec3 position, float scale, float rotationDeg, glm::vec3 rotationAxis);
        void Rotate(float angle, glm::vec3 axis);
        void Translate(glm:: vec3 newPosition);
};

#endif