/**
 * @author Connor Markwell (cmarkwe1)
 * @file
 * Implement some Color.hpp functions
 */

#include "Color.hpp"

// Empty Color constructor
Color::Color() {}

// Construct a Color with an R, G, and B value
Color::Color(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}