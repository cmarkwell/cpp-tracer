#ifndef LIGHT_H
#define LIGHT_H

#include "Object.hpp"
#include "Vector3.hpp"

class Light {

    public:
        // Light constructor
        Light(float x, float y, float z, float r, float g, float b);

        // Light destructor
        ~Light();

        // Position getter
        Vector3 get_position();

        // Color getter
        Color get_color();

    private:
        Vector3 m_pos;
        Color m_color;
};

#endif