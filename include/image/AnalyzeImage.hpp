/*
** EPITECH PROJECT, 2020
** Studio Mixx 2
** File description:
** AnalyzeImage
*/

#ifndef ANALYZEIMAGE_HPP_
#define ANALYZEIMAGE_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

#define MARGING 7

#define YELLOW sf::Color::Yellow
#define MAGENTA sf::Color::Magenta
#define CYAN sf::Color::Cyan
#define RED sf::Color::Red
#define BLUE sf::Color::Blue
#define GREEN sf::Color::Green

class AnalyzeImage {
    public:
        AnalyzeImage(sf::Sprite &sprite);
        ~AnalyzeImage();

        sf::Image &getImage() { return _renderedImage; };

        void convertToRGB();
        sf::Color compareToRGB(sf::Color clrToCmp);
        sf::Color compareToBW(sf::Color clrToCmp);
        sf::Color addColors(sf::Color shadowClr, sf::Color newClr);
        sf::Color colorRules(int c1, int c2, int c3, sf::Color toCompute);

    protected:
    private:
        sf::Image _image;
        sf::Image _renderedImage;
};

#endif /* !ANALYZEIMAGE_HPP_ */
