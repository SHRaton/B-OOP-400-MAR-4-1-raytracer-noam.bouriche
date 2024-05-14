/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** Sphere
*/

#include "../../include/Math.hpp"

using namespace Math;

Raytracer::Sphere::Sphere(Point3d center, double radius, std::string color)
{
    _center = center;
    _radius = radius;
    _color = color;
    _lenght = 0;
    _impact_point = Point3d(0, 0, 0);
    _normal = Vector3d(0, 0, 0);
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
        double t1 = (-b + sqrt(discriminant)) / (2.0 * a);
        double t2 = (-b - sqrt(discriminant)) / (2.0 * a);
        //std::cout << "t1= " << t1 << " / t2= " << t2 << std::endl;
        double t3;
        if (t1 < t2) {
            t3 = t1;
        } else {
            t3 = t2;
        }
        _lenght = t3;
        _impact_point = ray._origin + (ray._direction * t3);
        _normal.vector_from_two_point(_impact_point, _center);
        _normal.normalize();
        return true;
    } else {
        return false;
    }
}

bool Raytracer::Sphere::contains_point(Point3d p)
{
    Vector3d dis;
    dis.vector_from_two_point(p, _center);
    double distance_squared = dis.lenght();
    return distance_squared <= (_radius * _radius);
}

Point3d Raytracer::Sphere::get_impact_point()
{
    return (_impact_point);
}

Vector3d Raytracer::Sphere::get_normal()
{
    return (_normal);
}

double Raytracer::Sphere::get_lenght()
{
    return (_lenght);
}

std::string Raytracer::Sphere::get_color()
{
    return (_color);
}
