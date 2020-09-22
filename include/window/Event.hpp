/*
** EPITECH PROJECT, 2020
** Studio Mixx 2
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <SFML/Graphics.hpp>

class Event {
    public:
        Event(sf::RenderWindow *window);
        ~Event();

    void checkEvents(void);

    protected:
    private:
        sf::Event _event;
        sf::RenderWindow *_window;
};

#endif /* !EVENT_HPP_ */
