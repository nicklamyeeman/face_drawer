/*
** EPITECH PROJECT, 2020
** Studio Mixx 2
** File description:
** Window
*/

#include "Window.hpp"

Window::Window(int width, int height, std::string const name) : _window(sf::VideoMode(width, height), name)
{
    _width = width;
    _height = height;
}

Window::~Window()
{
}

void Window::startWindow(std::string const &filepath)
{
    UploadSprite face(filepath);
    AnalyzeImage face_analyzed(face.getSprite());

    _image = face_analyzed.getImage();
    UploadSprite compute(_image);

    while (_window.isOpen()) {
        Event event(&_window);
        event.checkEvents();

        _window.clear();
        _window.draw(compute.getSprite());
        _window.display();
    }
}

void Window::exportImage(std::string const &destPath)
{
    _image.saveToFile(destPath);
}