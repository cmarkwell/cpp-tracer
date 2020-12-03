/**
 * @author Connor Markwell (cmarkwe1)
 * @file
 * Implement the functions defined in Material.hpp
 */

#include "Material.hpp"
#include "Color.hpp"

// Empty Material constructor
Material::Material() {}

// Full material constructor
Material::Material(float r, float g, float b, float kd, float ks, float e) {
    color = Color(r, g, b);
    this->kd = kd;
    this->ks = ks;
    this->e = e;
}

// Material destructor
Material::~Material() {}