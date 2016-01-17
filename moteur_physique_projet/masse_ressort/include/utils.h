#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics.hpp>

namespace ut{

namespace vector{

float length(sf::Vector2f v);
float distance(sf::Vector2f v1, sf::Vector2f v2);
sf::Vector2f& normalize(sf::Vector2f& v);

}

}

#endif // UTILS_H

