/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** Core
*/

#include "../include/Core.hpp"
#include "../include/Math.hpp"

using namespace std;
using namespace Math;
using namespace Raytracer;

void Core::getFileName(const std::string& filePath)
{
    size_t lastSlashIndex = filePath.find_last_of('/');
    std::string fileNameWithExtension = filePath.substr(lastSlashIndex + 1);
    size_t lastDotIndex = fileNameWithExtension.find_last_of('.');
    std::string fileNameWithoutExtension = fileNameWithExtension.substr(0, lastDotIndex);
    std::string fileNameWithPPM = "renders/" + fileNameWithoutExtension + ".ppm";
    fileName = fileNameWithPPM;
}

void Core::loadfile(std::string str)
{
    try
    {
        cfg.readFile(str);
    }
    catch(const FileIOException &fioex)
    {
        std::cerr << "Erreur lors de la lecture du fichier de configuration." << std::endl;
        exit(EXIT_FAILURE);
    }
    catch(const ParseException &fioex)
    {
        std::cerr << "Erreur lors du parsing du fichier de configuration." << std::endl;
        exit(EXIT_FAILURE);
    }
    root = &cfg.getRoot();
}

Raytracer::Rectangle Core::get_cam_from_dir(Point3d origin, double ratio, std::string dir, double fov)
{
    Point3d x_plus(1, ratio, -1);
    Vector3d x_plus_bot(0, 0, 2);
    Vector3d x_plus_left(0, -2*ratio, 0);
    Point3d x_moins(-1, -ratio, -1);
    Vector3d x_moins_bot(0, 0, 2);
    Vector3d x_moins_left(0, 2*ratio, 0);

    Point3d y_plus(-ratio, 1, -1);
    Vector3d y_plus_bot(0, 0, 2);
    Vector3d y_plus_left(2*ratio, 0, 0);
    Point3d y_moins(ratio, -1, -1);
    Vector3d y_moins_bot(0, 0, 2);
    Vector3d y_moins_left(-2*ratio, 0, 0);

    Point3d z_plus(-1, -ratio, 1);
    Vector3d z_plus_bot(2, 0, 0);
    Vector3d z_plus_left(0, 2*ratio, 0);
    Point3d z_moins(-1, -ratio, -1);
    Vector3d z_moins_bot(2, 0, 0);
    Vector3d z_moins_left(0, 2*ratio, 0);

    if (dir == "+x") {
        origin._X += fov;
        return (Raytracer::Rectangle(x_plus + origin, x_plus_bot, x_plus_left));
    }
    if (dir == "-x") {
        origin._X -= fov;
        return (Raytracer::Rectangle(x_moins + origin, x_moins_bot, x_moins_left));
    }
    if (dir == "+y") {
        origin._Y += fov;
        return (Raytracer::Rectangle(y_plus + origin, y_plus_bot, y_plus_left));
    }
    if (dir == "-y") {
        origin._Y -= fov;
        return (Raytracer::Rectangle(y_moins + origin, y_moins_bot, y_moins_left));
    }
    if (dir == "+z") {
        origin._Z += fov;
        return (Raytracer::Rectangle(z_plus + origin, z_plus_bot, z_plus_left));
    }
    if (dir == "-z") {
        origin._Z -= fov;
        return (Raytracer::Rectangle(z_moins + origin, z_moins_bot, z_moins_left));
    }
    return (Raytracer::Rectangle(z_moins + origin, z_moins_bot, z_moins_left));
}
