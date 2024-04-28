/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** Camera
*/

#include "../../include/Math.hpp"

using namespace Math;

Raytracer::Rectangle::Rectangle(Point3d origin, Vector3d bottom_side, Vector3d left_side)
{
    _origin = origin;
    _bottom_side = bottom_side;
    _left_side = left_side;
}

Point3d Raytracer::Rectangle::pointAt(double u, double v) const
{
    //printf("_origin = %f %f %f / _bottom_side = %f %f %f / _left_side = %f %f %f\n", _origin._X, _origin._Y, _origin._Z, _bottom_side._X, _bottom_side._Y, _bottom_side._Z, _left_side._X, _left_side._Y, _left_side._Z);
    Point3d point = _origin + _bottom_side * u + _left_side * v;
    return point;
}
