/*
** EPITECH PROJECT, 2020
** Studio Mixx 2
** File description:
** UploadSprite
*/

#ifndef UPLOADSPRITE_HPP_
#define UPLOADSPRITE_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

class UploadSprite {
    public:
        UploadSprite(std::string const &filepath);
        UploadSprite(sf::Image const &image);
        ~UploadSprite();

        sf::Sprite &getSprite() { return _sprite; };

    protected:
    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
};

#endif /* !UPLOADSPRITE_HPP_ */
