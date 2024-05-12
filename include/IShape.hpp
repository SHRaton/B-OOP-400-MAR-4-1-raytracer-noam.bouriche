/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** IShape
*/

#pragma once

namespace Raytracer {
    class Ray;
}

namespace Math {
    class Point3d;
    class Vector3d;
}

class IShape {
    public:
        virtual ~IShape() = default;
        virtual bool hit(const Raytracer::Ray &ray) = 0;
        virtual std::string get_color() = 0;
        virtual double get_lenght() = 0;
        virtual Math::Point3d get_impact_point() = 0;
        virtual Math::Vector3d get_normal() = 0;
        virtual bool contains_point(const Math::Point3d p) = 0;
};
