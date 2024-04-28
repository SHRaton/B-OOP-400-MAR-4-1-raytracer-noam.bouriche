/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** Ray
*/

#include "../../include/Math.hpp"

using namespace Math;

Raytracer::Ray::Ray(const Point3d& origin, const Vector3d& direction)
{
    _origin = origin;
    _direction = direction;
}
