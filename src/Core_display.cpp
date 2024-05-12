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

sf::Image get_image_from_ppm(std::string fileName)
{
    std::ifstream ppmFile(fileName);
    if (!ppmFile.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier PPM" << std::endl;
        exit (84);
    }
    std::string magicNumber;
    ppmFile >> magicNumber;
    if (magicNumber != "P3") {
        std::cerr << "Format de fichier PPM non pris en charge" << std::endl;
        exit (84);
    }
    int width, height, maxValue;
    ppmFile >> width >> height >> maxValue;
    if (maxValue != 255) {
        std::cerr << "La profondeur de couleur n'est pas supportée (doit être 255)" << std::endl;
        exit (84);
    }
    sf::Image image;
    image.create(width, height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int r, g, b;
            ppmFile >> r >> g >> b;
            //std::cout << "r= " << r << " g= " << g << " b= " << b << std::endl;
            image.setPixel(x, y, sf::Color(r, g, b));
        }
    }
    return (image);
}

void Core::display_g()
{
    std::cout << fileName;
    sf::Image image = get_image_from_ppm(fileName);
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Image PPM");
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite(texture);
    sprite.setPosition(40, 135);
    sprite.setScale(0.75, 0.75);

    sf::Image img;
    sf::Texture tt;

    sf::Texture HUD_t;
    HUD_t.loadFromFile("assets/HUD.png");
    sf::Sprite HUD_s(HUD_t);

    sf::Texture HUD_button_t;
    HUD_button_t.loadFromFile("assets/HUD_button.png");
    sf::Sprite HUD_button_s(HUD_button_t);
    HUD_button_s.setPosition(1570, 900);

    sf::Texture load_t;
    load_t.loadFromFile("assets/load.png");
    sf::Sprite load_s(load_t);
    load_s.setPosition(1790, 920);
    load_s.setScale(0.3, 0.3);

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
    std::string all_files = "";
    std::string selected = "";

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        window.clear();
        window.draw(HUD_s);
        window.draw(HUD_button_s);
        window.draw(sprite);
        for (const auto& entry : std::filesystem::directory_iterator(directory)) {
            if (entry.is_regular_file()) {
                file.setString(std::string(entry.path().filename()));
                all_files += std::string(entry.path().filename()) + " ";
                file.setPosition(x, y);
                y+= 70;
                if (file.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                    file.setFillColor(sf::Color::Red);
                    if (event.type == sf::Event::MouseButtonPressed) {
                        selected = file.getString();
                    }
                } else {
                    file.setFillColor(sf::Color::Blue);
                }
                if (selected == file.getString()) {
                    file.setStyle(sf::Text::Underlined);
                } else {
                    file.setStyle(sf::Text::Regular);
                }
                window.draw(file);
            }
        }
        if (HUD_button_s.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
            if (event.type == sf::Event::MouseButtonPressed) {
                window.draw(load_s);
                window.display();
                raytracer_g("scenes/" + selected);
                getFileName(selected);
                img = get_image_from_ppm(fileName);
                sf::Vector2u imageSize = img.getSize();
                sprite.setTextureRect(sf::IntRect(0, 0, imageSize.x, imageSize.y));
                tt.loadFromImage(img);
                sprite.setTexture(tt);
                sprite.setPosition(40, 135);
                sprite.setScale(0.75, 0.75);
            }
        }
        y = 50;
        all_files.clear();
        window.display();
    }
}
