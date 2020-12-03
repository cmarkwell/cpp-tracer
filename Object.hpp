/**
 * @author Connor Markwell (cmarkwe1@umbc.edu)
 * @file
 * This file contains the function definitions for the
 * Object class. It serves as an abstraction for a 
 * 3-dimensional object.
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "Vector3.hpp"
#include "Material.hpp"
#include "Color.hpp"

class Object {
    public:
        // Object constructor
        Object();

        // Object destructor
        virtual ~Object();

        // Virtual intersection function to be implemented by children
        virtual float intersect(Vector3 e, Vector3 s) = 0;

        // Calculate surface normal of object given point on said object
        virtual Vector3 normal(Vector3 p) = 0;

        // Position getter
        const Vector3& get_position();

        // Material getter
        const Material& get_material();

    protected:
        Vector3 m_pos;          // Position vector
        Material m_material;    // Material property
};

#endif