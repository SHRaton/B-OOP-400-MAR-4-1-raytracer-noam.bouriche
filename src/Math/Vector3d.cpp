/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** Vector3d
*/

#include "../../include/Math.hpp"

using namespace Math;

Vector3d::Vector3d()
{
    _X = 0;
    _Y = 0;
    _Z = 0;
}

Vector3d::Vector3d(double x, double y, double z)
{
    _X = x;
    _Y = y;
    _Z = z;
}

double Vector3d::lenght()
{
    return (sqrt(_X*_X + _Y*_Y + _Z*_Z));
}

double Vector3d::dot(const Vector3d& vec) const
{
    return _X * vec._X + _Y * vec._Y + _Z * vec._Z;
}

void Vector3d::print()
{
    std::cout << "(x= '" << _X << "' y= '" << _Y << "' z= '" << _Z << "')" << std::endl;
}
