/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-noam.bouriche
** File description:
** Core_render
*/

#include "../include/Core.hpp"
#include "../include/Math.hpp"

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

using namespace std;
using namespace Math;
using namespace Raytracer;

void Core::display()
{
    std::ifstream ppmFile(fileName);
    if (!ppmFile.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier PPM" << std::endl;
        return;
    }
    std::string magicNumber;
    ppmFile >> magicNumber;
    if (magicNumber != "P3") {
        std::cerr << "Format de fichier PPM non pris en charge" << std::endl;
        return;
    }
    int width, height, maxValue;
    ppmFile >> width >> height >> maxValue;
    if (maxValue != 255) {
        std::cerr << "La profondeur de couleur n'est pas supportée (doit être 255)" << std::endl;
        return;
    }
    sf::Image image;
    image.create(width, height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int r, g, b;
            ppmFile >> r >> g >> b;
            image.setPixel(x, y, sf::Color(r, g, b));
        }
    }
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Image PPM");
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }

}

void Core::display_g()
{
    std::ifstream ppmFile(fileName);
    if (!ppmFile.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier PPM" << std::endl;
        return;
    }
    std::string magicNumber;
    ppmFile >> magicNumber;
    if (magicNumber != "P3") {
        std::cerr << "Format de fichier PPM non pris en charge" << std::endl;
        return;
    }
    int width, height, maxValue;
    ppmFile >> width >> height >> maxValue;
    if (maxValue != 255) {
        std::cerr << "La profondeur de couleur n'est pas supportée (doit être 255)" << std::endl;
        return;
    }
    sf::Image image;
    image.create(width, height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int r, g, b;
            ppmFile >> r >> g >> b;
            image.setPixel(x, y, sf::Color(r, g, b));
        }
    }
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Image PPM");
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite(texture);

    sf::Texture HUD_t;
    HUD_t.loadFromFile("assets/HUD.png");
    sf::Sprite HUD_s(HUD_t);

    std::string directory = "scenes";
    sf::Font font;
    if (!font.loadFromFile("assets/ArialNoir.ttf")) {
        return;
    }
    sf::Text file;
    file.setFont(font);
    file.setString("Ouais");
    file.setCharacterSize(50);
    file.setFillColor(sf::Color::Blue);
    int x = 1550, y = 20;
    file.setPosition(x, y);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        window.clear();
        window.draw(sprite);
        window.draw(HUD_s);
        for (const auto& entry : std::filesystem::directory_iterator(directory)) {
            if (entry.is_regular_file()) {
                //std::cout << entry.path().filename() << std::endl;
                file.setString(std::string(entry.path().filename()));
                file.setPosition(x, y);
                y+= 70;
                window.draw(file);
            }
        }
        y = 50;
        window.display();
    }
}
