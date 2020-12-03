/**
 * @author Connor Markwell (cmarkwe1@umbc.edu)
 * @file
 * This file contains the implementations for
 * (some) of the functions defined in Object.hpp
 */

#include "Object.hpp"
#include "Vector3.hpp"
#include "Material.hpp"

// Object constructor
Object::Object() {}

// Object destructor
Object::~Object() {}

// Position getter
const Vector3& Object::get_position() {
    return m_pos;
}

// Color getter
const Material& Object::get_material() {
    return m_material;
}