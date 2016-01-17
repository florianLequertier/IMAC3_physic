#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#include <SFML/Graphics.hpp>

#include "../include/modeleur.h"


int main(int argc, char **argv)
{
    Modeleur modeleur;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            modeleur.compute();

            window.clear();
            window.draw(modeleur);
            window.display();
        }

        return 0;

}
