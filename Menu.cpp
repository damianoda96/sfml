#include <SFML/Graphics.hpp>
#include <../Menu.h>

Menu::Menu()
{
     if (!font.loadFromFile("resources/Anonymous_Pro.ttf"))
        printf("Cannot find font file!");

    titleText.setFont(font);
    titleText.setCharacterSize(40);
    titleText.setPosition(170.f, 150.f);
    titleText.setFillColor(sf::Color::White);
    titleText.setString("PLATFORMER\nPRESS TAB TO START");

    gameOverText.setFont(font);
    gameOverText.setCharacterSize(40);
    gameOverText.setPosition(170.f, 150.f);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setString("GAME OVER\nPRESS TAB TO RESTART");

    levelText.setFont(font);
    levelText.setCharacterSize(40);
    levelText.setPosition(170.f, 150.f);
    levelText.setFillColor(sf::Color::White);
}
