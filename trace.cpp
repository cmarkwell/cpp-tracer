/**
 * @author Connor Markwell (cmarkwe1@umbc.edu)
 * @file
 * This file contains the main function for the project, and 
 * the implementation of a raytracing algorithm, complete with
 * diffuse, specular, and mirror shading.
 */

#define _USES_MATH_DEFINES

#define BOUNCE_LIMIT 5
#define CONTRIBUTION_LIMIT 1/255

#include "NFFScene.hpp"
#include "Vector3.hpp"
#include "Pixel.hpp"
#include "Color.hpp"

#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>

NFFScene *scene;

bool is_light_occluded(Vector3 from, Vector3 at) {
    for (unsigned int i = 0; i < scene->objects.size(); i++) {
        float t = scene->objects[i]->intersect(from, at);
        if (t < 1 && t >= 1e-10) {
            return true;
        }
    }
    return false;
}

Color trace(Vector3 from, Vector3 at, float contribution) {
    float t0 = 0, t1 = std::numeric_limits<float>::infinity(), t;
    bool did_hit = false;
    int hit_idx;

    // Find closest intersected object
    for (unsigned int i = 0; i < scene->objects.size(); i++) {
        t = scene->objects[i]->intersect(from, at);
        if (t < t1 && t > t0) {
            t1 = t;
            hit_idx = i;
            did_hit = true;
        }
    }

    // If an intersection was found, shade
    if (did_hit) {
        Color local_color(0, 0, 0);
        Material hit_mat = scene->objects[hit_idx]->get_material();
        float diffuse, specular, lr, lg, lb;
        float intensity = 1/std::sqrt(scene->lights.size());
        Vector3 l, h;
        Vector3 p = from + at * t1;
        Vector3 v = (from - p).normalize();
        Vector3 n = scene->objects[hit_idx]->normal(p).normalize();
        Vector3 r = (v * -1) + n * (2 * n.dot(v));
        // Loop through point lights to calculate diffuse and specular hl
        for (unsigned int i = 0; i < scene->lights.size(); i++) {
            l = (scene->lights[i]->get_position() - p).normalize();
            h = (l + v).normalize();
            lr = scene->lights[i]->get_color().r * intensity;
            lg = scene->lights[i]->get_color().g * intensity;
            lb = scene->lights[i]->get_color().b * intensity;
            if (!is_light_occluded(p, l)) {
                diffuse = std::max(0.0f, n.dot(l));
                specular = std::pow(std::max(0.0f, n.dot(h)), hit_mat.e);
                local_color.r += 
                    (hit_mat.kd * hit_mat.color.r + hit_mat.ks * specular) 
                    * diffuse * lr;
                local_color.g += 
                    (hit_mat.kd * hit_mat.color.g + hit_mat.ks * specular) 
                    * diffuse * lg;
                local_color.b += 
                    (hit_mat.kd * hit_mat.color.b + hit_mat.ks * specular) 
                    * diffuse * lb;
            }
        }
        // Recursively compute mirror reflections
        if (contribution > CONTRIBUTION_LIMIT) {
            Color reflection = trace(p, r, contribution * hit_mat.ks);
            local_color.r += hit_mat.ks * reflection.r;
            local_color.g += hit_mat.ks * reflection.g;
            local_color.b += hit_mat.ks * reflection.b;
        }
        return local_color;
    }
    return scene->background_color;
}

int main(int argc, char* argv[]) {
    scene = new NFFScene(argv[1]);

    // Check scene readiness
    if (!scene->is_open) {
        std::cout 
            << "Unable to open file \"" 
            << (argv[1] ? argv[1] : "")
            << "\""<< std::endl;
        return 0;
    }

    // Parse given nff file
    std::cout << "Parsing " << argv[1] << std::endl;
    scene->parse();

    // RGB Pixel array
    Pixel *image = new Pixel[scene->height * scene->width];
    Pixel *pixel = image;

    // Calculate basis vectors
    Vector3 w0 = scene->from - scene->at;
    float d = w0.mag();
    Vector3 w = w0.normalize();
    Vector3 u = w.cross(scene->up).normalize();
    Vector3 v = w.cross(u);

    // Calculate image window dimensions
    float angle_radians = scene->angle * M_PI / 180;
    float top = d * std::tan(angle_radians / 2);
    float bottom = -top;
    float right = top;
    float left = -top;

    Vector3 s, p;
    float vs, us;

    // Iterate from 0 to image height
    for (int i = 0; i < scene->height; i++) {
        vs = bottom + (top - bottom) * (i + 0.5) / scene->height;
        std::cout << "\r"
            << "Tracing row " << (i + 1) << "/" << scene->height 
            << std::flush;
        // Iterate from 0 to image width
        for (int j = 0; j < scene->width; j++, pixel++) {
            us = right + (left - right) * (j + 0.5) / scene->width;
            // Calculate pixel vector
            s = scene->from + (u * us) + (v * vs) - (w * d);
            p = s - scene->from;
            *pixel = trace(scene->from, p, 1);
        }
    }

    std::cout << std::endl; 

    // Write pixels to ppm file
    const char *filename = (argv[2] ? argv[2] : "trace.ppm");
    FILE *f = fopen(filename, "wb");
    fprintf(f, "P6\n%d %d\n255\n", scene->width, scene->height);
    fwrite(image, 1, scene->width * scene->height * 3, f);
    fclose(f);

    std::cout << "Output written to " << filename << std::endl;

    // Perform object cleanup
    delete[] image;
    delete scene;

    return 0;
}
