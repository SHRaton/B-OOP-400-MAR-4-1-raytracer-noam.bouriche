/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** main
*/

#pragma once

#include <cstdio>
#include <cstring>
#include <iostream>
#include <libconfig.h++>
#include <vector>
#include <memory>
#include <utility>
#include "IShape.hpp"

using namespace libconfig;

class Core {
    public :
        Core();
        ~Core();
        void loadfile(std::string str);
        void draw_render_ppm(std::string name);
        void parse_all();
        Config cfg;
        Setting *root;

    public :
        std::pair<int, int> resolution;
        std::vector<std::unique_ptr<IShape>> primitives;
};

void raytracer(char **av);
