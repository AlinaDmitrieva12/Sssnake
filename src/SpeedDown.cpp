#include "SpeedDown.h"

SpeedDown::SpeedDown() {
    texture.loadFromFile("../res/speeddown.png");
    block.setTexture(texture);
    sf::Vector2f initialSpeedDownPosition = {10 * BLOCK_SIZE, 15 * BLOCK_SIZE};
    block.setPosition(initialSpeedDownPosition);
}

float SpeedDown::updatePosition(float &delay) {
    delay += 0.3;
    sf::Vector2f newSpeedDownPosition = {(float) (rand() % GAME_WIDTH) * BLOCK_SIZE,
                                         (float) (rand() % GAME_HEIGHT) * BLOCK_SIZE};
    block.setPosition(newSpeedDownPosition);
    return delay;
}

sf::Vector2f SpeedDown::getPosition() {
    return block.getPosition();
}