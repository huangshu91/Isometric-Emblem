/*
 * FriendlyFire.cpp
 *
 *  Created on: Jul 24, 2012
 *      Author: Maiev
 */

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 200), "SFML works!");
    sf::Text text("Hello SFML2");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}
