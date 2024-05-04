/*
** EPITECH PROJECT, 2024
** ù
** File description:
** Point3d
*/

#include "../../include/Math.hpp"

using namespace Math;

Point3d::Point3d(double x, double y, double z)
{
    _X = x;
    _Y = y;
    _Z = z;
}

Point3d::Point3d()
{
    _X = 0;
    _Y = 0;
    _Z = 0;
}

void Point3d::print()
{
    std::cout << "(x= '" << _X << "' y= '" << _Y << "' z= '" << _Z << "')" << std::endl;
}
