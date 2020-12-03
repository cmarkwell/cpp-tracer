/**
 * @author Connor Markwell (cmarkwe1@umbc.edu)
 * @file
 * This file defines a Color struct, which is a simple
 * object that contains a R, G, and B value
 */

#ifndef COLOR_H
#define COLOR_H

struct Color {
    Color();
    Color(float r, float g, float b);
    float r, g, b;
};

#endif