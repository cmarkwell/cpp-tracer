/**
 * @author Connor Markwell (cmarkwe1@umbc.edu)
 * @file
 * This file contains the implementations for the
 * function definitions specified in Sphere.hpp.
 */

#include "Sphere.hpp"
#include "Object.hpp"
#include "Vector3.hpp"

#include <cmath>
#include <iostream>
#include <limits>

// Basic sphere constructor
Sphere::Sphere(float x, float y, float z, float r, Material material) {
    m_pos = Vector3(x, y, z);
    m_radius = r;
    m_material = material;
}

// Sphere destructor
Sphere::~Sphere() {};

// Calculate possible ray-sphere intersect values
float Sphere::intersect(Vector3 e, Vector3 p) {
    float a = p.dot(p);
    float b = 2 * (p).dot(e - m_pos);
    float c = (e - m_pos).dot(e - m_pos) - (m_radius * m_radius);
    float discriminant = (b * b) - (4 * a * c);

    if (discriminant < 0) { 
        return std::numeric_limits<float>::infinity();
    }

    float t0 = (-b + std::sqrt(discriminant)) / (2*a);
    float t1 = (-b - std::sqrt(discriminant)) / (2*a);

    return t0 < t1 ? t0 : t1;
}

Vector3 Sphere::normal(Vector3 p) {
    return p - m_pos;
}
