#include "Light.hpp"
#include "Vector3.hpp"

Light::Light(float x, float y, float z, float r, float g, float b) {
    m_pos = Vector3(x, y, z);
    m_color = Color(r, g, b);
}

Light::~Light () {};

Color Light::get_color() {
    return m_color;
}

Vector3 Light::get_position() {
    return m_pos;
}