#include "light.h"

Light::Light(glm::vec3 position, glm::vec4 color, int type)
{
    Light::position = position;
    Light::color = color;
    Light::type = type;
}