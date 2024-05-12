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
}

class ILight {
    public:
        virtual ~ILight() = default;
        virtual bool is_shadow(const Raytracer::Ray &ray) = 0;
        virtual std::string get_color() = 0;
        virtual double get_direction() = 0;
        virtual Math::Point3d get_impact_point() = 0;
};
