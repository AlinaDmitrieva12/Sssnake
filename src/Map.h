#ifndef _MAP_H_
#define _MAP_H_

#include "GameConstants.h"

class Map {
public:
    sf::Sprite block;
    sf::Texture texture;

    Map();

    void draw(sf::RenderWindow &window);
};

#endif //_MAP_H_
