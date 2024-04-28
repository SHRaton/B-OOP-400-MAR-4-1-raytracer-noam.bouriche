/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** Core
*/

#include "../include/Core.hpp"
#include "../include/Math.hpp"

Core::Core()
{
}

Core::~Core()
{
}

void Core::loadfile(std::string str)
{
    try
    {
        cfg.readFile("scenes/basic.cfg");
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

void Core::parse_all()
{
    int x, y;
    (*root)["camera"]["resolution"].lookupValue("width", x);
    (*root)["camera"]["resolution"].lookupValue("height", y);
    std::pair<int, int> res = {x, y};
    resolution = res;


    auto s = std::make_unique<Raytracer::Sphere>(Math::Point3d(60, 5, 50), 25);
    primitives.push_back(std::move(s));
}
