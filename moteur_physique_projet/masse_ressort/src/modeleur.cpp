
#include <iostream>
#include "../include/modeleur.h"
#include "../include/link.h"
#include "../include/utils.h"


void LinkAlgo_ressort::compute(double h, Link* link)
{
    float d = ut::vector::distance( link->M1->position, link->M2->position );
    if(d < 0.00000001f)
        return;

    float f = link->k * (1.f-link->l/d);
    if(std::abs(f) < 0.00000001f)
        return;

    sf::Vector2f  M1M2 = link->M2->position - link->M1->position;
    ut::vector::normalize(M1M2);
    if(ut::vector::length(M1M2) < 0.00000001f)
        return;

    //frein :
    sf::Vector2f frein = link->z*(link->M2->vitesse - link->M1->vitesse);

    link->M1->force += (f * M1M2 + frein);
    link->M2->force += (-f * M1M2 - frein);

    std::cout<<"force de rappel en M1 : "<<link->M1->force.x<<", "<<link->M1->force.y<<std::endl;
    std::cout<<"force de rappel en M2 : "<<link->M2->force.x<<", "<<link->M2->force.y<<std::endl;
}


void PmatAlgo_fixe::compute(float h, Pmat* matRef)
{
    //initialyze force buffer
    matRef->force = sf::Vector2f(0,0);
}

void PmatAlgo_particule::compute(float h, Pmat *matRef)
{
    if(matRef->masse < 0.000001f)
        return;

    //leapfrog
    matRef->vitesse += (h/matRef->masse)*matRef->force;
    matRef->position += h*matRef->vitesse;
    matRef->force = sf::Vector2f(0,0);
}

Modeleur::Modeleur() : h(0.01f), gravity(0.f, 1.f)
{
    int pointNumber = 100;

    graphicalPoints.setPrimitiveType(sf::Points);
    graphicalLines.setPrimitiveType(sf::LinesStrip);

    pointContainer.resize(pointNumber);
    linkContainer.resize(pointNumber - 1);

    algoPMat = new PmatAlgo_particule();
    algoLink = new LinkAlgo_ressort();

    initialize_zigzag();
    //initialize_verticalLine();
}

void Modeleur::initialize_zigzag()
{
    for(int i = 0; i < pointContainer.size(); ++i)
    {

        pointContainer[i].position = sf::Vector2f(i*8.f, rand()%300 + 100.f);

        pointContainer[i].masse = (i == 0 || i == (pointContainer.size() - 1)) ? 0.f : 1.f;

        sf::Vertex newVertex(pointContainer[i].position, sf::Color::Red);
        graphicalPoints.append(newVertex);
        graphicalLines.append(newVertex);
    }


    for(int i = 0; i < pointContainer.size() - 1; ++i)
    {
        linkContainer[i].setConnection( &pointContainer[i], &pointContainer[i+1] );
        //linkContainer[i].l = ut::vector::distance(M1->position, M2->position);
        linkContainer[i].l = 8.f;
        linkContainer[i].k = 1000.f;
        linkContainer[i].z = 1.f;
    }
}


void Modeleur::initialize_verticalLine()
{
    for(int i = 0; i < pointContainer.size(); ++i)
    {
        pointContainer[i].position = sf::Vector2f( 300 + i ,i*3.f + 60);

        pointContainer[i].masse = (i == 0 ) ? 0.f : .1f;

        sf::Vertex newVertex(pointContainer[i].position,
                             sf::Color(i * 255.f / (float)pointContainer.size(), 255.f - i * 255.f / (float)pointContainer.size(), 0 , 255));
        graphicalPoints.append(newVertex);
        graphicalLines.append(newVertex);
    }


    for(int i = 0; i < pointContainer.size() - 1; ++i)
    {
        linkContainer[i].setConnection( &pointContainer[i], &pointContainer[i+1] );
        //linkContainer[i].l = ut::vector::distance(M1->position, M2->position);
        linkContainer[i].l = std::sqrt(10.f);
        linkContainer[i].k = 1000.f;
        linkContainer[i].z = 0.f;
    }
}

void Modeleur::compute()
{
    //update joints :
    for(int i = 0; i < linkContainer.size(); ++i)
    {
        algoLink->compute(h, &linkContainer[i]);
    }

    //update points :
    for(int i = 0; i < pointContainer.size(); ++i)
    {

        //add gravity :
        pointContainer[i].force += gravity;

        //resolve movements with leapfrog :
        algoPMat->compute(h, &pointContainer[i]);

        //update graphics for points :
        graphicalPoints[i].position = pointContainer[i].position;
        //update graphics for lines :
        graphicalLines[i].position = pointContainer[i].position;
    }

}

void Modeleur::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //draw
    target.draw( graphicalPoints );
    target.draw( graphicalLines );
}


void Modeleur::setH(float _h)
{
    h = _h;
}

float Modeleur::getH() const
{
    return h;
}

sf::Vector2f Modeleur::getGravity() const
{
    return gravity;
}

void Modeleur::setGravity(const sf::Vector2f& _gravity)
{
    gravity = _gravity;
}
