/**
 * @author Connor Markwell (cmarkwe1@umbc.edu)
 * @file
 * This file contains the implementations for the
 * function definitions specified in Vector3.hpp
 */

#include "Vector3.hpp"

#include <cmath>

// Vector3 constructor
Vector3::Vector3(float x, float y, float z) {
    m_x = x;
    m_y = y;
    m_z = z;
}

// Overloaded addition operator, returns new vector
Vector3 Vector3::operator+(const Vector3 &rhs) {
    Vector3 vec;
    vec.m_x = m_x + rhs.m_x;
    vec.m_y = m_y + rhs.m_y;
    vec.m_z = m_z + rhs.m_z;
    return vec;
}

// Overloaded subtraction operator, returns new vector
Vector3 Vector3::operator-(const Vector3 &rhs) {
    Vector3 vec;
    vec.m_x = m_x - rhs.m_x;
    vec.m_y = m_y - rhs.m_y;
    vec.m_z = m_z - rhs.m_z;
    return vec;
}

// Multiply x, y, and z components of a vector by a scalar
Vector3 Vector3::operator*(float scalar) {
    Vector3 vec;
    vec.m_x = scalar * m_x;
    vec.m_y = scalar * m_y;
    vec.m_z = scalar * m_z;
    return vec;
}

// Divide x, y, and z components of a vector by a number
Vector3 Vector3::operator/(float divisor) {
    Vector3 vec;
    vec.m_x = m_x / divisor;
    vec.m_y = m_y / divisor;
    vec.m_z = m_z / divisor;
    return vec;
}

// Calculate the dot product of two vectors
float Vector3::dot(const Vector3 &vector) {
    return (m_x * vector.m_x) 
        + (m_y * vector.m_y) 
        + (m_z * vector.m_z);
}

// Compute new vector with cross product
Vector3 Vector3::cross(const Vector3 &vector) {
    Vector3 vec;
    vec.m_x = (m_y * vector.m_z) - (vector.m_y * m_z);
    vec.m_y = (m_z * vector.m_x) - (vector.m_z * m_x);
    vec.m_z = (m_x * vector.m_y) - (vector.m_x * m_y); 
    return vec;
}

// Calculate magnitude of vector
float Vector3::mag() {
    return std::sqrt(std::pow(m_x, 2) 
        + std::pow(m_y, 2) 
        + std::pow(m_z, 2));
}

// Return unit length vector
Vector3 Vector3::normalize() {
    Vector3 vec;
    float magn = mag();
    vec.m_x = m_x / magn;
    vec.m_y = m_y / magn;
    vec.m_z = m_z / magn;
    return vec;
}

float Vector3::get_x() {
    return m_x;
}

float Vector3::get_y() {
    return m_y;
}

float Vector3::get_z() {
    return m_z;
}

void Vector3::set_x(float x) {
    m_x = x;
}

void Vector3::set_y(float y) {
    m_y = y;
}

void Vector3::set_z(float z) {
    m_z = z;
}