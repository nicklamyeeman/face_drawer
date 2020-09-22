/*
** EPITECH PROJECT, 2020
** Studio Mixx 2
** File description:
** UploadSprite
*/

#include "UploadSprite.hpp"

UploadSprite::UploadSprite(std::string const &filepath)
{
    _texture.loadFromFile(filepath);
    _sprite.setTexture(_texture);
}

UploadSprite::UploadSprite(sf::Image const &image)
{
    _texture.loadFromImage(image);
    _sprite.setTexture(_texture);
}


UploadSprite::~UploadSprite()
{
}
