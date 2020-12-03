/**
 * @author Connor Markwell (cmarkwe1@umbc.edu)
 * @file
 * This file contains the function definitions for the
 * Vector3 class. It serves as a 3-dimensional vector
 * representation.
 */

#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
    public:
        // Constructor
        Vector3(float x = 0, float y = 0, float z = 0);

        // Vector addition (non-mutating)
        Vector3 operator+(const Vector3 &rhs);

        // Vector subtraction (non-mutating)
        Vector3 operator-(const Vector3 &rhs);

        // Vector scaling (non-mutating)
        Vector3 operator*(float scalar);

        // Vector reducing (non mutating)
        Vector3 operator/(float divisor);

        // Vector dot product
        float dot(const Vector3 &vector);

        // Vector cross product
        Vector3 cross(const Vector3 &vector);

        // Vector magnitude
        float mag();

        // Vector normalization
        Vector3 normalize();

        // X-Coordinate getter
        float get_x();

        // Y-Coordinate getter
        float get_y();

        // Z-Coorindate getter
        float get_z();

        // X-Coordinate setter
        void set_x(float x);

        // Y-Coordinate setter
        void set_y(float y);

        // Z-Coorindate setter
        void set_z(float z);

    private:
        float m_x; // X-Coordinate
        float m_y; // Y-Coordinate
        float m_z; // Z-Coordinate

};

#endif
