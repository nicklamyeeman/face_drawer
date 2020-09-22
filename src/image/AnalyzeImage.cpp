/*
** EPITECH PROJECT, 2020
** Studio Mixx 2
** File description:
** AnalyzeImage
*/

#include "AnalyzeImage.hpp"

AnalyzeImage::AnalyzeImage(sf::Sprite &sprite)
{
    _image = sprite.getTexture()->copyToImage();
    _renderedImage = sprite.getTexture()->copyToImage();

    this->convertToRGB();
}

AnalyzeImage::~AnalyzeImage()
{
}

void AnalyzeImage::convertToRGB()
{
    for (int i = 0; i != (int)_image.getSize().x; i++)
        for (int j = 0; j != (int)_image.getSize().y; j++) {
            sf::Color clrToCmp = _image.getPixel(i, j);

            sf::Color shadowClr = this->compareToBW(clrToCmp);
            sf::Color newClr = this->compareToRGB(clrToCmp);

            _renderedImage.setPixel(i, j, this->addColors(shadowClr, newClr));
        }
}

sf::Color AnalyzeImage::addColors(sf::Color shadowClr, sf::Color newClr)
{
    int r = (int)shadowClr.r + (int)newClr.r;
    int g = (int)shadowClr.g + (int)newClr.g;
    int b = (int)shadowClr.b + (int)newClr.b;

    return (sf::Color(
                (r < 255) ? r : 255,
                (g < 255) ? g : 255,
                (b < 255) ? b : 255
            ));
}

sf::Color AnalyzeImage::compareToBW(sf::Color clrToCmp)
{
    int r = clrToCmp.r;
    int g = clrToCmp.g;
    int b = clrToCmp.b;

    int average = (r + g + b) / 3;

    if (average < 85)
        return (sf::Color::Black);
    if (average > 170)
        return (sf::Color::White);
    return (sf::Color(127, 127, 127));
}

sf::Color AnalyzeImage::compareToRGB(sf::Color clrToCmp)
{
    int r = clrToCmp.r;
    int g = clrToCmp.g;
    int b = clrToCmp.b;

    if (r - g >= -1 * MARGING && r - g <= MARGING)
        return (this->colorRules(r, g, b, YELLOW));
    if (g - b >= -1 * MARGING && g - b <= MARGING)
        return (this->colorRules(g, b, r, MAGENTA));
    if (b - r >= -1 * MARGING && b - r <= MARGING)
        return (this->colorRules(b, r, g, CYAN));
    
    if (r >= g && r >= b)
        return (RED);
    if (g >= r && g >= b)
        return (GREEN);
    if (b >= r && b >= g)
        return (BLUE);
    return (sf::Color::Black);
}

sf::Color AnalyzeImage::colorRules(int c1, int c2, int c3, sf::Color toCompute)
{
    if ((c1 - c3 >= -1 * MARGING && c1 - c3 <= MARGING) ||
        (c2 - c3 >= -1 * MARGING && c2 - c3 <= MARGING)) {
            int average = (c1 + c2 + c3) / 3;
            if (average < 170)
                return (sf::Color::Black);
            else
                return (sf::Color::White);
        }
    else
        return (toCompute);
}