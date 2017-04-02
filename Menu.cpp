#include <SFML/Graphics.hpp>
#include <../Menu.h>

Menu::Menu()
{
     if (!titleFont.loadFromFile("resources/Anonymous_Pro.ttf"))
        printf("Cannot find font file!");

    titleText.setFont(titleFont);
    titleText.setCharacterSize(40);
    titleText.setPosition(170.f, 150.f);
    titleText.setFillColor(sf::Color::White);
    titleText.setString("My Game");
}
