/**
 * @author Connor Markwell (cmarkwe1@umbc.edu)
 * @file
 * This file defines Sphere as a subclass of Object, and
 * defines a constructor and intersect function
 */

#ifndef SPHERE_H
#define SPHERE_H

#include "Object.hpp"

class Sphere: public Object {
    public:
        // Sphere constructor
        Sphere(float x, float y, float z, float r, Material material);

        // Sphere desctructor
        ~Sphere();

        // Ray-Sphere intersect function
        float intersect(Vector3 e, Vector3 p);

        // Surface normal function
        Vector3 normal(Vector3 p);

    private:
        float m_radius;    // Sphere radius
};

#endif
