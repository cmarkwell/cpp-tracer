/**
 * @author Connor Markwell (cmarkwe1)
 * @file
 * This file defines a Material class, which has a color and some 
 * other related surface properties
 */

#ifndef MATERIAL_H
#define MATERIAL_H

#include "Color.hpp"

struct Material {
    Material();
    Material(float r, float g, float b, float kd, float ks, float e);
    ~Material();
    Color color;
    float kd;
    float ks;
    float e;
};

#endif