#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "GameConstants.h"

class Snake {
public:
    int dir = 2;
    int width = 3;
    int color = 1;
    sf::Sprite blocks[GAME_WIDTH * GAME_HEIGHT];
    sf::Texture texture;
    sf::Vector2f headPosition;

    Snake();

    void updateColors(int colorNumber);

    void update();

    void updateDirection();

    void draw(sf::RenderWindow &window, bool isLose);

    bool checkLose();

    bool checkAppleCollision(const sf::Vector2f &applePosition);

    bool checkOrangeCollision(const sf::Vector2f &orangePosition);

    bool checkSpeedUpCollision(const sf::Vector2f &speedUpPosition) const;

    bool checkSpeedDownCollision(const sf::Vector2f &speedDownPosition) const;
};

#endif //_SNAKE_H_
