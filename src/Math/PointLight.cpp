/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** Rectangle
*/

#include "../../include/Math.hpp"

using namespace Math;

Raytracer::PointLight::PointLight(Point3d coo)
{
    _name = "PointLight";
    _color = "255 255 255\n";
    _coo = coo;
    _direction = Vector3d(0, 0, 0);
}

std::string Raytracer::PointLight::get_name()
{
    return (_name);
}

std::string Raytracer::PointLight::get_color()
{
    return (_color);
}

Point3d Raytracer::PointLight::get_position()
{
    return (_coo);
}

Vector3d Raytracer::PointLight::get_direction()
{
    return (_direction);
}
