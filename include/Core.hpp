/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** main
*/

#pragma once

#include <cstdio>
#include <cstring>
#include <iostream>
#include <libconfig.h++>
#include <vector>
#include <memory>
#include <utility>
#include <limits>
#include <sstream>
#include <algorithm>
#include "Math.hpp"

using namespace libconfig;

class Core {
    public :
        Core() = default;
        ~Core() = default;
        void loadfile(std::string str);
        void draw_render_ppm(std::string name);
        std::string add_pixel_color(Raytracer::Ray r);
        Raytracer::Rectangle get_cam_from_dir(Point3d origin, double ratio, std::string dir, double fov);
        void getFileName(const std::string& filePath);
        void display();
        void display_g();
        void parse_all();
        void parse_camera();
        void parse_primitives();
        void parse_lights();
        std::string shadow_gestion(int closest_primitive, size_t i);
        std::string color_from_vector(Vector3d color);
        Vector3d vector_from_color(std::string color);
        Config cfg;
        Setting *root;
        std::string fileName;

    public :
        // Camera
        std::pair<int, int> _camera_resolution;
        Math::Point3d _camera_origin;
        Raytracer::Rectangle _camera_rect;
        double _camera_fov;
        Raytracer::Camera _camera;

        // Primitives
        std::vector<std::unique_ptr<IShape>> _primitives;

        // Lights
        std::vector<std::unique_ptr<ILight>> _lights;
        double ambiant_light;
        double diffuse_light;
};

void raytracer(char **av);
void raytracer_g(std::string path);
