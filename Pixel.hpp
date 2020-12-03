/**
 * @author Connor Markwell (cmarkwe1)
 * @file
 * Define a Pixel class that will be used in an array to write an image
 * to
 */
#ifndef PIXEL_H
#define PIXEL_H

#include "Color.hpp"

struct Pixel {
    Pixel();
    Pixel(Color c);
    unsigned char r, g, b;
};

#endif