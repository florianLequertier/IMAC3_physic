#ifndef MAT_H
#define MAT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#include <SFML/Graphics.hpp>

static const float g  = 10.f;

class Pmat
{
public :

    sf::Vector2f position;
    sf::Vector2f vitesse;
    sf::Vector2f force;
    float masse;

    Pmat();
    Pmat(sf::Vector2f _position);
    Pmat(sf::Vector2f _position, sf::Vector2f _vitesse, float _masse);

    void setMasse(double _masse);
    void setForce(sf::Vector2f _force);
    void setVitesse(sf::Vector2f _vitesse);
    void setPosition(sf::Vector2f _position);
    void draw();

//    void algo_pFixe(double h);
//    void algo_particule(double h);

};

#endif // MAT_H

