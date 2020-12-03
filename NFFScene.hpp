/**
 * @author Connor Markwell (cmarkwe1@umbc.edu)
 * @file
 * This file contains the function definitions for the
 * NFFScene class. It serves as a parser for a given
 * file in the NFF format.
 */

#ifndef NFFSCENE_H
#define NFFSCENE_H

#include "Vector3.hpp"
#include "Object.hpp"
#include "Sphere.hpp"
#include "Color.hpp"
#include "Light.hpp"
#include "Material.hpp"

#include <iostream>
#include <fstream>
#include <vector>

struct NFFScene {
    // Constructor for given filename
    NFFScene(char *file);

    // Destructor
    ~NFFScene();

    // Parse nff file
    void parse();

    std::ifstream nff;              // Input file stream
    bool is_open;                   // Input file open status
    Color background_color;         // Using vector to store background RGB
    Material object_material;       // Vector to store current object RGB values
    Vector3 from;                   // Camera viewpoint
    Vector3 at;                     // Camera view direction
    Vector3 up;                     // Orientation vector
    float angle;                    // Camera FOV
    int width;                      // Width of image 
    int height;                     // Height of image
    std::vector<Object*> objects;   // Scene objects
    std::vector<Light*> lights;     // Scene point lights
};

#endif
