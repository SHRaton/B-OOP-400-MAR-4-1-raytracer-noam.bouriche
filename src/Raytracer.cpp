/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** raytracer
*/

#include "../include/Core.hpp"
#include "../include/Math.hpp"

using namespace libconfig;

void raytracer(char **av)
{
    Core core;
    core.loadfile(std::string(av[1]));
    core.parse_all();

    core.getFileName(std::string(av[1]));
    core.draw_render_ppm(core.fileName);
    if (av[2] == NULL) {
        core.display();
    }
    if (av[2] != NULL && std::string(av[2]) == "-g") {
        core.display_g();
    }
}
