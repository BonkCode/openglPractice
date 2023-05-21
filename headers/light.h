#ifndef LIGHT_H
# define LIGHT_H


# define L_NONE -1
# define L_POINT 0
# define L_DIREC 1
# define L_SPOT 2

# include "../glm/glm.hpp"

class Light
{
    public:
        glm::vec3 position;
        glm::vec4 color;
        int type;

        Light(glm::vec3 position, glm::vec4 color, int type);
};

#endif