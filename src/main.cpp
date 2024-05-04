/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** main
*/

#include "../include/Core.hpp"
#include "../include/Math.hpp"

using namespace libconfig;

void print_help(char **av)
{
    if (strcmp(av[1], "--help") == 0){
        std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
        std::cout << "  SCENE_FILE: scene configuration" << std::endl;
        exit (0);
    }
}

int main(int ac, char **av)
{
    if (ac > 3 || ac == 1) {
        return (84);
    }
    print_help(av);
    raytracer(av);
    return (0);
}
