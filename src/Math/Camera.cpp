/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** Rectangle
*/

#include "../../include/Math.hpp"

using namespace Math;

Raytracer::Camera::Camera()
{
    Point3d ori(0, 0, 0);
    _origin = ori;
    _screen_size_x = 1920.0;
    _screen_size_y = 1080.0;
    _ratio = _screen_size_x / _screen_size_y;
    _screen._origin = Point3d(-1, -_ratio, -1);
    _screen._bottom_side = Vector3d(2, 0, 0);
    _screen._left_side = Vector3d(0, 2*_ratio, 0);
    //printf("_origin = %f %f %f / _bottom_side = %f %f %f / _left_side = %f %f %f\n", _origin._X, _origin._Y, _origin._Z, _screen._bottom_side._X, _screen._bottom_side._Y, _screen._bottom_side._Z, _screen._left_side._X, _screen._left_side._Y, _screen._left_side._Z);
}

Raytracer::Camera::Camera(Point3d origin, Rectangle screen, double screen_size_x, double screen_size_y, double fov)
{
    _origin = origin;
    _screen = screen;
    _screen_size_x = screen_size_x;
    _screen_size_y = screen_size_y;
    _ratio = _screen_size_x / _screen_size_y;
    _fov = fov;
}

Raytracer::Ray Raytracer::Camera::ray(double u, double v) const
{
    Point3d screenPoint = _screen.pointAt(u, v);
    Point3d dir = screenPoint - _origin;
    Vector3d direction(dir._X, dir._Y, dir._Z);
    //printf("screenPoint : (%.1f %.1f %.1f)\n", screenPoint._X, screenPoint._Y, screenPoint._Z);
    //printf("direction : (%.1f %.1f %.1f)\n", direction._X, direction._Y, direction._Z);
    return Ray(_origin, direction);
}
