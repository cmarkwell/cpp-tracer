#include "Pixel.hpp"

// Empty Pixel constructor
Pixel::Pixel() {}

// Clamp pixel colors between 0 and 255
Pixel::Pixel(Color c) {
    r = (c.r < 0) ? 0 : (c.r > 1) ? 255 : (unsigned char)(c.r * 255);
    g = (c.g < 0) ? 0 : (c.g > 1) ? 255 : (unsigned char)(c.g * 255);
    b = (c.b < 0) ? 0 : (c.b > 1) ? 255 : (unsigned char)(c.b * 255);
}