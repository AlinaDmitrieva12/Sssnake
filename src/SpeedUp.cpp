#include "SpeedUp.h"

SpeedUp::SpeedUp() {
    texture.loadFromFile("../res/speedup.png");
    block.setTexture(texture);
    sf::Vector2f initialSpeedUpPosition = {15 * BLOCK_SIZE, 15 * BLOCK_SIZE};
    block.setPosition(initialSpeedUpPosition);
}

float SpeedUp::updatePosition(float &delay) {
    delay -= 0.3;
    sf::Vector2f newSpeedUpPosition = {(float) (rand() % GAME_WIDTH) * BLOCK_SIZE,
                                       (float) (rand() % GAME_HEIGHT) * BLOCK_SIZE};
    block.setPosition(newSpeedUpPosition);
    return delay;
}

sf::Vector2f SpeedUp::getPosition() {
    return block.getPosition();
}