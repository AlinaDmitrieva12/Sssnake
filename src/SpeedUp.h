#ifndef _SPEEDUP_H_
#define _SPEEDUP_H_

#include "GameConstants.h"

class SpeedUp {
public:
    sf::Sprite block;
    sf::Texture texture;

    SpeedUp();

    float updatePosition(float &delay);

    sf::Vector2f getPosition();
};

#endif //_SPEEDUP_H_
