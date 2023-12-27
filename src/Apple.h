#ifndef _APPLE_H_
#define _APPLE_H_

#include <SFML/Graphics.hpp>
#include "GameConstants.h"

class Apple {
public:
    sf::Sprite block;
    sf::Texture texture;

    Apple();

    void updatePosition();

    sf::Vector2f getPosition();
};

#endif //_APPLE_H_
