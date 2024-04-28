/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** raytracer
*/

#include "../include/Core.hpp"
#include "../include/Math.hpp"

using namespace libconfig;

Raytracer::Rectangle get_cam_from_dir(Point3d origin, double ratio, std::string dir)
{
    Point3d x_plus(1, -ratio, -1);
    Vector3d x_plus_bot(0, 0, 2);
    Vector3d x_plus_left(0, 2*ratio, 0);
    Point3d x_moins(-1, -ratio, -1);
    Vector3d x_moins_bot(0, 0, 2);
    Vector3d x_moins_left(0, 2*ratio, 0);
    Point3d y_plus(-ratio, 1, -1);
    Vector3d y_plus_bot(0, 0, 2);
    Vector3d y_plus_left(2*ratio, 0, 0);
    Point3d y_moins(-ratio, -1, -1);
    Vector3d y_moins_bot(0, 0, 2);
    Vector3d y_moins_left(2*ratio, 0, 0);
    Point3d z_plus(-1, -ratio, 1);
    Vector3d z_plus_bot(2, 0, 0);
    Vector3d z_plus_left(0, 2*ratio, 0);
    Point3d z_moins(-1, -ratio, -1);
    Vector3d z_moins_bot(2, 0, 0);
    Vector3d z_moins_left(0, 2*ratio, 0);

    if (dir == "+x") {
        return (Raytracer::Rectangle(x_plus + origin, x_plus_bot, x_plus_left));
    }
    if (dir == "-x") {
        return (Raytracer::Rectangle(x_moins + origin, x_moins_bot, x_plus_left));
    }
    if (dir == "+y") {
        return (Raytracer::Rectangle(y_plus + origin, y_plus_bot, y_plus_left));
    }
    if (dir == "-y") {
        return (Raytracer::Rectangle(y_moins + origin, y_moins_bot, y_moins_left));
    }
    if (dir == "+z") {
        return (Raytracer::Rectangle(z_plus + origin, z_plus_bot, z_plus_left));
    }
    if (dir == "-z") {
        return (Raytracer::Rectangle(z_moins + origin, z_moins_bot, z_moins_left));
    }
    return (Raytracer::Rectangle(z_moins + origin, z_moins_bot, z_moins_left));
}

void Core::draw_render_ppm(std::string name)
{
    double a = resolution.first;
    double b = resolution.second;
    double ratio = a / b;

    Point3d origin(0, -100, 20);

    Raytracer::Rectangle cam_rect = get_cam_from_dir(origin, ratio, "+y");

    Raytracer::Camera cam(origin, cam_rect, a, b);
    Raytracer::Sphere s(Math::Point3d(60, 5, 50), 25);
    Raytracer::Sphere s2(Math::Point3d(0, 2, 4), 0.5);
    Raytracer::Sphere s3(Math::Point3d(-40, 20, -10), 35);
    Raytracer::Sphere s4(Math::Point3d(0, -4, 0), 0.5);
    Raytracer::Sphere s5(Math::Point3d(4, 0, 0), 0.5);
    Raytracer::Sphere s6(Math::Point3d(-4, 0, 0), 0.5);

    std::ofstream fichier(name);

    fichier << "P3\n" << cam._screen_size_x << ' ' << cam._screen_size_y << "\n255\n";
    for (double x = 0; x < cam._screen_size_y; x++) {
        for (double y = 0; y < cam._screen_size_x; y++) {
            double u = x / cam._screen_size_y;
            double v = y / cam._screen_size_x;
            Raytracer::Ray r = cam.ray(u, v);
            if (s.hit(r)) {
                fichier << "255 0 0\n";
            } else if (s2.hit(r)) {
                fichier << "255 255 0\n";
            } else if (s3.hit(r)) {
                fichier << "0 255 0\n";
            } else if (s4.hit(r)) {
                fichier << "0 0 255\n";
            } else if (s5.hit(r)) {
                fichier << "0 255 255\n";
            } else if (s6.hit(r)) {
                fichier << "255 0 255\n";
            } else {
                fichier << "0 0 0\n";
            }
        }
    }
    fichier.close();
}

void raytracer(char **av)
{
    Core core;
    core.loadfile(std::string(av[1]));
    core.parse_all();

    core.draw_render_ppm("renders/image66.ppm");
}
