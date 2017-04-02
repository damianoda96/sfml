#include <SFML/Graphics.hpp>
#include <../Platform.h>

Platform::Platform()
{
    //Create Platform
    platformSize.x = 100.f;
    platformSize.y = 25.f;
    platformRect.setSize(platformSize);
    platformRect.setOutlineThickness(2);
    platformRect.setOutlineColor(sf::Color::White);
    platformRect.setFillColor(sf::Color::Blue);
    platformRect.setOrigin(platformSize / 2.f);
}

float Platform::getPlatformTop()
{
    return(platformRect.getPosition().y - platformSize.y/2.f);
}

float Platform::getPlatformBottom()
{
    return(platformRect.getPosition().y + platformSize.y/2.f);
}

float Platform::getPlatformLeft()
{
    return(platformRect.getPosition().x - platformSize.x/2.f);
}

float Platform::getPlatformRight()
{
    return(platformRect.getPosition().x + platformSize.x/2.f);
}
