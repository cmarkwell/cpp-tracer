/**
 * @author Connor Markwell (cmarkwe1@umbc.edu)
 * @file
 * This file contains the implementations for the
 * function definitions specified by NFFScene.hpp
 */

#include "NFFScene.hpp"
#include "Sphere.hpp"
#include "Object.hpp"
#include "Light.hpp"
#include "Material.hpp"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

// Open given file, set is_open variable accordingly
NFFScene::NFFScene(char *file) {
    nff.open(file);
    is_open = nff.is_open();
}

// Close opened file on destruct
NFFScene::~NFFScene() {
    nff.close();
    for (Object *object : objects) {
        delete object;
    }
    objects.clear();
    for (Light *light : lights) {
        delete light;
    }
    lights.clear();
}

// Parse an opened nff file for the required variables
void NFFScene::parse() {
    std::string line;
    std::string flag;
    float x, y, z, a, b, c = 0;
    while (std::getline(nff, line)) {
        std::stringstream stream(line);
        stream >> flag >> x >> y >> z >> a;
        if (flag == "from") {
            from = Vector3(x, y, z);
        } else if (flag == "at") {
            at = Vector3(x, y, z);
        } else if (flag == "up") {
            up = Vector3(x, y, z);
        } else if (flag == "angle") {
            angle = x;
        } else if (flag == "resolution") {
            width = x;
            height = y;
        } else if (flag == "b") {
            background_color = Color(x, y, z);
        } else if (flag == "f") {
            stream >> b >> c;
            object_material = Material(x, y, z, a, b, c);
        } else if (flag == "s") {
            objects.push_back(new Sphere(x, y, z, a, object_material));
        } else if (flag == "l") {
            if (stream.peek() == -1) { 
                a = 1; b = 1; c = 1;
            } else {
                stream >> b >> c; 
            } 
            lights.push_back(new Light(x, y, z, a, b, c));
        }
    }
}
