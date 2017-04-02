#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SFML/Graphics.hpp>

struct Menu
{
//Initialize pause message
    sf::Text titleText;

    // Load the text font
    sf::Font titleFont;

    Menu();
};

#endif // MENU_H_INCLUDED
