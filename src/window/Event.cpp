/*
** EPITECH PROJECT, 2020
** Studio Mixx 2
** File description:
** Event
*/

#include "Event.hpp"

Event::Event(sf::RenderWindow *window)
{
    _window = window;
}

Event::~Event()
{
}

void Event::checkEvents(void)
{
    while (_window->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window->close();
    }
}