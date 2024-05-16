/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** IShape
*/

#include <iostream>

#pragma once

namespace Raytracer {
    class Ray;
}

namespace Math {
    class Point3d;
    class Vector3d;
}

class ILight {
    public:
        virtual ~ILight() = default;
        virtual std::string get_name() = 0;
        virtual std::string get_color() = 0;
        virtual Math::Point3d get_position() = 0;
        virtual Math::Vector3d get_direction() = 0;
};
