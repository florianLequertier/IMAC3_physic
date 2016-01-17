#include "../include/utils.h"


namespace ut{

namespace vector{

float length(sf::Vector2f v){
    return std::sqrt( v.x*v.x + v.y*v.y );
}

float distance(sf::Vector2f v1, sf::Vector2f v2)
{
    return std::sqrt( (v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y) );
}

sf::Vector2f& normalize(sf::Vector2f& v)
{
    float VLength = length(v);
    if(VLength < 0.0000001f)
    {
        v = sf::Vector2f(100000000, 1000000000);
        return v;
    }

    v /= VLength;

    return v;
}

}

}
