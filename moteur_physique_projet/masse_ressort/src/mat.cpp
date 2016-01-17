#include "../include/mat.h"


Pmat::Pmat(): vitesse(0,0), masse(0), force(0,0), position(0,0)
{

}

Pmat::Pmat(sf::Vector2f _position) : vitesse(0,0), masse(0), force(0,0), position(_position)
{

}

Pmat::Pmat(sf::Vector2f _position, sf::Vector2f _vitesse, float _masse) : vitesse(_vitesse), masse(_masse), force(0,0), position(_position)
{

}

void Pmat::setMasse(double _masse)
{
    masse = _masse;
}

void Pmat::setForce(sf::Vector2f _force)
{
    force = _force;
}

void Pmat::setVitesse(sf::Vector2f _vitesse)
{
    vitesse = _vitesse;
}

void Pmat::setPosition(sf::Vector2f _position)
{
    position = _position;
}

void Pmat::draw()
{
    //todo
}


//void Pmat::algo_pFixe(double h)
//{
//    //initialyze force buffer
//    force = 0;
//}

//void Pmat::algo_particule(double h)
//{
//    //leapfrog
//    vitesse += (h/m)*force;
//    position += h*vitesse;
//    force = 0;
//}

