#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SFML/Graphics.hpp>

struct Menu
{
    //Initialize pause message
    sf::Text titleText;

    //Initialize game over message
    sf::Text gameOverText;

    // Load the text font
    sf::Font font;



    Menu();
};

#endif // MENU_H_INCLUDED
