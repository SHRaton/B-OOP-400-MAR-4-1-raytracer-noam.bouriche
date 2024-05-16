/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** Parsing
*/

#include "../include/Core.hpp"
#include "../include/Math.hpp"

using namespace std;
using namespace Math;
using namespace Raytracer;

double calculate_coefficient(float fov_degrees)
{
    double fov_radians = fov_degrees * M_PI / 180.0;
    double tan_half_fov = tanf(fov_radians / 2.0);
    double coefficient = 1.0 / (2.0 * tan_half_fov);

    return coefficient;
}

void Core::parse_camera()
{
    int res_x, res_y;
    (*root)["camera"]["resolution"].lookupValue("width", res_x);
    (*root)["camera"]["resolution"].lookupValue("height", res_y);
    _camera_resolution = {res_x, res_y};

    double fov;
    (*root)["camera"].lookupValue("fieldOfView", fov);
    _camera_fov = fov;

    int ori_x, ori_y, ori_z;
    (*root)["camera"]["position"].lookupValue("x", ori_x);
    (*root)["camera"]["position"].lookupValue("y", ori_y);
    (*root)["camera"]["position"].lookupValue("z", ori_z);
    _camera_origin = Math::Point3d(ori_x, ori_y, ori_z);

    double a = _camera_resolution.first;
    double b = _camera_resolution.second;
    double ratio = a / b;
    double fov_ratio = calculate_coefficient(_camera_fov);
    std::string dir;
    (*root)["camera"].lookupValue("direction", dir);
    _camera_rect = get_cam_from_dir(_camera_origin, ratio, dir, fov_ratio);

    std::cout << "{origin = " << ori_x << " " << ori_y << " " << ori_z << "}, {rect = " << "origin(x=" << _camera_rect._origin._X << " y=" << _camera_rect._origin._Y << " z=" << _camera_rect._origin._Z << ") / bot = " << "(x=" << _camera_rect._bottom_side._X << " y=" << _camera_rect._bottom_side._Y << " z=" << _camera_rect._bottom_side._Z << ") / left" << "(x=" << _camera_rect._left_side._X << " y=" << _camera_rect._left_side._Y << " z=" << _camera_rect._left_side._Z << ") /" << " resolution = " << "x=" << _camera_resolution.first << " y=" << _camera_resolution.second << "}" << std::endl;
    _camera = Raytracer::Camera(_camera_origin, _camera_rect, _camera_resolution.first, _camera_resolution.second, _camera_fov);
    std::cout << _camera._screen.pointAt(1, 1)._X << " " << _camera._screen.pointAt(1, 1)._Y << " " << _camera._screen.pointAt(1, 1)._Z << "\n";

}

void Core::parse_primitives()
{
    int z = 0;
    int nb = (*root)["primitives"].getLength();

    while (z < nb) {
        if (std::string((*root)["primitives"][z].getName()) == "spheres") {
            for (int i = 0; i < (*root)["primitives"]["spheres"].getLength(); i++) {
                int x, y, z, r;
                int color_r, color_g, color_b;
                (*root)["primitives"]["spheres"][i].lookupValue("x", x);
                (*root)["primitives"]["spheres"][i].lookupValue("y", y);
                (*root)["primitives"]["spheres"][i].lookupValue("z", z);
                (*root)["primitives"]["spheres"][i].lookupValue("r", r);
                (*root)["primitives"]["spheres"][i]["color"].lookupValue("r", color_r);
                (*root)["primitives"]["spheres"][i]["color"].lookupValue("g", color_g);
                (*root)["primitives"]["spheres"][i]["color"].lookupValue("b", color_b);
                std::string color = std::to_string(color_r) + " " + std::to_string(color_g) + " " + std::to_string(color_b) + "\n";
                auto sphere = make_unique<Sphere>(Point3d(x, y, z), r, color);
                _primitives.push_back(std::move(sphere));
            }
        }
        if (std::string((*root)["primitives"][z].getName()) == "planes") {
            for (int i = 0; i < (*root)["primitives"]["planes"].getLength(); i++) {
                std::string axis;
                int pos, color_r, color_g, color_b;
                (*root)["primitives"]["planes"][i].lookupValue("axis", axis);
                (*root)["primitives"]["planes"][i].lookupValue("position", pos);
                (*root)["primitives"]["planes"][i]["color"].lookupValue("r", color_r);
                (*root)["primitives"]["planes"][i]["color"].lookupValue("g", color_g);
                (*root)["primitives"]["planes"][i]["color"].lookupValue("b", color_b);
                std::string color = std::to_string(color_r) + " " + std::to_string(color_g) + " " + std::to_string(color_b) + "\n";
                auto plan = make_unique<Plan>(axis, pos, color);
                _primitives.push_back(std::move(plan));
            }
        }
        z++;
    }
}

void Core::parse_lights()
{
    int z = 0;
    int nb = (*root)["lights"].getLength();

    while (z < nb) {
        if (std::string((*root)["lights"][z].getName()) == "ambient") {
            (*root)["lights"].lookupValue("ambient", ambiant_light);
        }
        if (std::string((*root)["lights"][z].getName()) == "diffuse") {
            (*root)["lights"].lookupValue("diffuse", diffuse_light);
        }
        if (std::string((*root)["lights"][z].getName()) == "point") {
            for (int i = 0; i < (*root)["lights"]["point"].getLength(); i++) {
                int x, y, z;
                (*root)["lights"]["point"][i].lookupValue("x", x);
                (*root)["lights"]["point"][i].lookupValue("y", y);
                (*root)["lights"]["point"][i].lookupValue("z", z);
                Point3d coo(x, y, z);
                auto light = make_unique<PointLight>(coo);
                _lights.push_back(std::move(light));
            }
        }
        z++;
    }
}

void Core::parse_all()
{
    parse_camera();
    parse_primitives();
    parse_lights();
}
