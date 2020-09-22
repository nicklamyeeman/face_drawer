/*
** EPITECH PROJECT, 2020
** Studio Mixx 2
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Event.hpp"
#include "UploadSprite.hpp"
#include "AnalyzeImage.hpp"

class Window {
   public:
        Window(int height, int width, std::string const name);
        ~Window();

    void startWindow(std::string const &filepath);
    void exportImage(std::string const &destPath);

    int getWidth(void) { return (_width); }
    int getHeight(void) { return (_height); }

    protected:
    private:
        int _width;
        int _height;
        sf::RenderWindow _window;
        sf::Image _image;
};

#endif /* !WINDOW_HPP_ */
