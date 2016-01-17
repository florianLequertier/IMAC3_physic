#ifndef MODELEUR_H
#define MODELEUR_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <vector>

#include <SFML/Graphics.hpp>

#include "link.h"
#include "mat.h"

class LinkAlgo
{
public:
    virtual void compute(double h, Link *link ) = 0;
};

class LinkAlgo_ressort : public LinkAlgo
{
public:
    virtual void compute(double h, Link *link);
};

class PmatAlgo
{
public:
    virtual void compute(float h, Pmat* matRef) = 0;
};

class PmatAlgo_fixe : public PmatAlgo
{
public:
    virtual void compute(float h, Pmat* matRef);
};

class PmatAlgo_particule : public PmatAlgo
{
public:
    virtual void compute(float h, Pmat* matRef);
};


class Modeleur : public sf::Drawable
{
private :
    double h;

    std::vector<Pmat> pointContainer;
    std::vector<Link> linkContainer;

    sf::VertexArray graphicalPoints;
    sf::VertexArray graphicalLines;

    PmatAlgo* algoPMat;
    LinkAlgo* algoLink;

    sf::Vector2f gravity;

public :
    Modeleur();

    void initialize_zigzag();
    void initialize_verticalLine();

    void compute();

    void setH(float _h);

    float getH() const;

    sf::Vector2f getGravity() const;

    void setGravity(const sf::Vector2f &_gravity);

private :
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // MODELEUR_H

