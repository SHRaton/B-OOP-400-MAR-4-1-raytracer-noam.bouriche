/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** Core_render
*/

#include "../include/Core.hpp"
#include "../include/Math.hpp"

using namespace std;
using namespace Math;
using namespace Raytracer;

std::string Core::add_pixel_color(Ray r)
{
    double min_distance = std::numeric_limits<double>::infinity();
    int closest_primitive_index = -1;

    for (size_t i = 0; i < _primitives.size(); ++i) {
        if (_primitives[i]->hit(r)) {
            double distance = _primitives[i]->get_lenght();
            if (distance < min_distance) {
                min_distance = distance;
                closest_primitive_index = i;
            }
        }
    }
    if (closest_primitive_index != -1) {
        return _primitives[closest_primitive_index]->get_color();
    }
    return "0 0 0\n";
}

void Core::draw_render_ppm(std::string name)
{
    std::ofstream fichier(name);
    Ray r;

    fichier << "P3\n" << _camera._screen_size_x << ' ' << _camera._screen_size_y << "\n255\n";
    for (double x = 0; x < _camera._screen_size_y; x++) {
        for (double y = 0; y < _camera._screen_size_x; y++) {
            double u = 1 - (x / _camera._screen_size_y);
            double v = y / _camera._screen_size_x;
            r = _camera.ray(u, v);
            fichier << add_pixel_color(r);
        }
    }
    fichier.close();
}
