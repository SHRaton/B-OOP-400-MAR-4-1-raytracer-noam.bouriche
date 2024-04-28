/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** IShape
*/

#pragma once

//#include "Math.hpp"
namespace Raytracer {
    class Ray;
}

class IShape {
    public:
        virtual ~IShape() = default;
        virtual bool hit(const Raytracer::Ray &ray) = 0;
};
