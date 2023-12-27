#ifndef _ORANGE_H_
#define _ORANGE_H_

#include "GameConstants.h"

class Orange {
public:
    sf::Sprite block;
    sf::Texture texture;

    Orange();

    void updatePosition();

    sf::Vector2f getPosition();
};

#endif //_ORANGE_H_
