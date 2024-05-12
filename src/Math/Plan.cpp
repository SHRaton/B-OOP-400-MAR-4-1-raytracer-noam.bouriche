/*
** EPITECH PROJECT, 2024
** ù
** File description:
** Plan
*/

#include "../../include/Math.hpp"

using namespace Math;

Raytracer::Plan::Plan(std::string axis, double pos, std::string color)
{
    _axis = axis;
    _pos = pos;
    _color = color;
    _lenght = 0;
    _impact_point = Point3d(0, 0, 0);
    _normal = Vector3d(0, 0, 0);
}

bool Raytracer::Plan::hit(const Raytracer::Ray& ray)
{
    Vector3d normal;
    Point3d point_on_plane(0, 0, 0);
    if (_axis == "X") {
        normal = Vector3d(1, 0, 0);
        point_on_plane._X = _pos;
    } else if (_axis == "Y") {
        normal = Vector3d(0, 1, 0);
        point_on_plane._Y = _pos;
    } else if (_axis == "Z") {
        normal = Vector3d(0, 0, 1);
        point_on_plane._Z = _pos;
    } else {
        return false;
    }
    double denominator = normal.dot(ray._direction);
    constexpr double EPSILON = 1e-6;
    if (abs(denominator) < EPSILON) {
        return false;
    }
    Vector3d origin_to_point;
    origin_to_point._X = point_on_plane._X - ray._origin._X;
    origin_to_point._Y = point_on_plane._Y - ray._origin._Y;
    origin_to_point._Z = point_on_plane._Z - ray._origin._Z;
    double t = origin_to_point.dot(normal) / denominator;
    if (t < 0) {
        return false;
    }
    _lenght = t;
    _impact_point = ray._origin + (ray._direction * t);
    if (_axis == "X") {
        _normal = Vector3d(1, 0, 0);
    }
    if (_axis == "Y") {
        _normal = Vector3d(0, 1, 0);
    }
    if (_axis == "Z") {
        _normal = Vector3d(0, 0, 1);
    }
    return true;
}

bool Raytracer::Plan::contains_point(Point3d p)
{
    if (_axis == "X" && std::abs(p._X - _pos) < 0.0001) {
        return true;
    }
    if (_axis == "Y" && std::abs(p._Y - _pos) < 0.0001) {
        return true;
    }
    if (_axis == "Z" && std::abs(p._Z - _pos) < 0.0001) {
        return true;
    }
    return false;
}

double Raytracer::Plan::get_lenght()
{
    return (_lenght);
}

Point3d Raytracer::Plan::get_impact_point()
{
    return (_impact_point);
}

Vector3d Raytracer::Plan::get_normal()
{
    return (_normal);
}

std::string Raytracer::Plan::get_color()
{
    return (_color);
}
