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

Vector3d darken_color(const Vector3d& color, double factor)
{
    factor = std::max(0.0, std::min(1.0, factor));
    int r = static_cast<int>(color._X * factor);
    int g = static_cast<int>(color._Y * factor);
    int b = static_cast<int>(color._Z * factor);

    return Vector3d(r, g, b);
}

std::string Core::shadow_gestion(int i)
{
    Point3d impact = _primitives[i]->get_impact_point();
    Vector3d light_direction;
    light_direction.vector_from_two_point(Point3d(400, 100, 500), impact);
    Raytracer::Ray r_light(impact + (light_direction * 0.0001), light_direction);
    for (size_t z = 0; z < _primitives.size(); ++z) {
        if (_primitives[z]->hit(r_light)) {
            return("shadow\n");
        }
    }
    return ("nothing");
}

Vector3d compute_lambert_shading(const Vector3d& normal, const Vector3d& light_direction, const Vector3d& diffuse_color)
{
    double diffuse_intensity = std::max(0.0, normal.dot(light_direction));
    diffuse_intensity = diffuse_intensity * (1.0 * 0.5) + 0.5;
    return diffuse_color * diffuse_intensity;
}

std::string Core::add_pixel_color(Ray r)
{
    double min_distance = std::numeric_limits<double>::infinity();
    int closest_primitive_index = -1;
    std::string shadow;

    for (size_t i = 0; i < _primitives.size(); ++i) {
        if (_primitives[i]->hit(r)) {
            double distance = _primitives[i]->get_lenght();
            if (distance < min_distance) {
                min_distance = distance;
                closest_primitive_index = i;
            }
        }
    }
    Vector3d color;
    Vector3d ambient_light(0.8, 0.8, 0.8);
    Vector3d shading_color;
    Vector3d normal;
    Point3d impact;
    Vector3d light_direction;
    if (closest_primitive_index != -1) {
        shadow = shadow_gestion(closest_primitive_index);
        if (shadow != "nothing") {
            color = darken_color(vector_from_color(_primitives[closest_primitive_index]->get_color()), 0.5);
        } else {
            color = vector_from_color(_primitives[closest_primitive_index]->get_color());
            normal = _primitives[closest_primitive_index]->get_normal();
            impact = _primitives[closest_primitive_index]->get_impact_point();
            light_direction.vector_from_two_point(Point3d(400, 100, 500), impact);
            light_direction.normalize();
            shading_color = compute_lambert_shading(normal, light_direction, vector_from_color(_primitives[closest_primitive_index]->get_color()));
            color = shading_color;
        }
    } else {
        color = Vector3d(0, 0, 0);
    }
    color *= ambient_light;
    return color_from_vector(color);
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
