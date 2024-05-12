/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** Math
*/

#pragma once

#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "IShape.hpp"

using namespace std;

namespace Math {
    class Vector3d {
        public:
        Vector3d();
        Vector3d(double x, double y, double z);
        ~Vector3d() = default;
        double _X;
        double _Y;
        double _Z;
        double lenght();
        double dot(const Vector3d& vec) const;
        void vector_from_two_point(Point3d p1, Point3d p2);
        void print();
        void normalize();
        Vector3d operator+(const Vector3d& v) const {
            return Vector3d(_X + v._X, _Y + v._Y, _Z + v._Z);
        }
        Vector3d& operator+=(const Vector3d& v) {
            _X += v._X;
            _Y += v._Y;
            _Z += v._Z;
            return *this;
        }
        Vector3d operator-(const Vector3d& v) const {
            return Vector3d(_X - v._X, _Y - v._Y, _Z - v._Z);
        }
        Vector3d& operator-=(const Vector3d& v) {
            _X -= v._X;
            _Y -= v._Y;
            _Z -= v._Z;
            return *this;
        }
        Vector3d operator*(const Vector3d& v) const {
            return Vector3d(_X * v._X, _Y * v._Y, _Z * v._Z);
        }
        Vector3d& operator*=(const Vector3d& v) {
            _X *= v._X;
            _Y *= v._Y;
            _Z *= v._Z;
            return *this;
        }
        Vector3d operator/(const Vector3d& v) const {
            return Vector3d(_X / v._X, _Y / v._Y, _Z / v._Z);
        }
        Vector3d& operator/=(const Vector3d& v) {
            _X /= v._X;
            _Y /= v._Y;
            _Z /= v._Z;
            return *this;
        }

        Vector3d operator*(const double ratio) const {
            return Vector3d(_X * ratio, _Y * ratio, _Z * ratio);
        }
        Vector3d& operator*=(const double ratio) {
            _X *= ratio;
            _Y *= ratio;
            _Z *= ratio;
            return *this;
        }
        Vector3d operator/(const double ratio) const {
            return Vector3d(_X / ratio, _Y / ratio, _Z / ratio);
        }
        Vector3d& operator/=(const double ratio) {
            _X /= ratio;
            _Y /= ratio;
            _Z /= ratio;
            return *this;
        }
    };
    class Point3d {
        public:
        Point3d();
        Point3d(double x, double y, double z);
        ~Point3d() = default;
        double _X;
        double _Y;
        double _Z;
        void print();
        Point3d operator+(const Vector3d& v) const {
            return Point3d(_X + v._X, _Y + v._Y, _Z + v._Z);
        }
        Point3d operator-(const Vector3d& v) const {
            return Point3d(_X - v._X, _Y - v._Y, _Z - v._Z);
        }
        Point3d operator+(const Point3d& v) const {
            return Point3d(_X + v._X, _Y + v._Y, _Z + v._Z);
        }
        Point3d operator-(const Point3d& v) const {
            return Point3d(_X - v._X, _Y - v._Y, _Z - v._Z);
        }
        Point3d operator*(const Point3d& v) const {
            return Point3d(_X * v._X, _Y * v._Y, _Z * v._Z);
        }
    };
};
using namespace Math;

namespace Raytracer {
    class Ray {
        public :
        Ray() = default;
        ~Ray() = default;
        Ray(const Point3d& origin, const Vector3d& direction);
        Point3d _origin;
        Vector3d _direction;
    };
    class Sphere : public IShape {
        public :
        Sphere() = default;
        ~Sphere() = default;
        Sphere(Point3d center, double radius, std::string color);
        bool hit(const Raytracer::Ray& ray);
        std::string get_color();
        double get_lenght();
        Point3d get_impact_point();
        Vector3d get_normal();
        bool contains_point(Point3d p);

        Point3d _center;
        double _radius;
        std::string _color;
        double _lenght;
        Point3d _impact_point;
        Vector3d _normal;
    };
    class Plan : public IShape {
        public:
        Plan() = default;
        ~Plan() = default;
        Plan(std::string axis, double pos, std::string color);
        bool hit(const Raytracer::Ray& ray);
        std::string get_color();
        double get_lenght();
        Point3d get_impact_point();
        Vector3d get_normal();
        bool contains_point(Point3d p);

        std::string _axis;
        double _pos;
        std::string _color;
        double _lenght;
        Point3d _impact_point;
        Vector3d _normal;
    };
    class Rectangle {
        public :
        Rectangle() = default;
        Rectangle(Point3d origin, Vector3d bottom_side, Vector3d left_side);
        ~Rectangle() = default;
        Point3d _origin;
        Vector3d _bottom_side;
        Vector3d _left_side;
        Point3d pointAt(double u, double v) const;
    };
    class Camera {
        public :
        Camera();
        Camera(Point3d origin, Rectangle screen, double screen_size_x, double screen_size_y, double fov);
        ~Camera() = default;
        Point3d _origin;
        Rectangle _screen;
        double _screen_size_x;
        double _screen_size_y;
        double _ratio;
        double _fov;
        Ray ray(double u, double v) const;
    };
};
