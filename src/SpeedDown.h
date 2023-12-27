#ifndef _SPEEDDOWN_H_
#define _SPEEDDOWN_H_

#include "GameConstants.h"

class SpeedDown {
public:
    sf::Sprite block;
    sf::Texture texture;

    SpeedDown();

    float updatePosition(float &delay);

    sf::Vector2f getPosition();
};

#endif //_SPEEDDOWN_H_
