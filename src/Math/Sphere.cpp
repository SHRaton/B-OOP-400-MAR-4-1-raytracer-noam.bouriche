/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** Sphere
*/

#include "../../include/Math.hpp"

using namespace Math;

Raytracer::Sphere::Sphere(Point3d center, double radius)
{
    _center = center;
    _radius = radius;
}

bool Raytracer::Sphere::hit(const Raytracer::Ray& ray)
{
    Vector3d oc;
    oc._X = ray._origin._X - _center._X;
    oc._Y = ray._origin._Y - _center._Y;
    oc._Z = ray._origin._Z - _center._Z;
    double a = ray._direction.dot(ray._direction);
    double b = 2.0 * oc.dot(ray._direction);
    double c = oc.dot(oc) - _radius * _radius;

    double discriminant = b * b - 4.0 * a * c;

    if (discriminant >= 0 && b < 0) {
        return true;
    } else {
        return false;
    }
}
