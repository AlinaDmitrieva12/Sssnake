#include "Apple.h"

Apple::Apple() {
    texture.loadFromFile("../res/apple.png");
    block.setTexture(texture);
    sf::Vector2f initialApplePosition = {10 * BLOCK_SIZE, 10 * BLOCK_SIZE};
    block.setPosition(initialApplePosition);
}

void Apple::updatePosition() {
    sf::Vector2f newApplePosition = {(float) (rand() % GAME_WIDTH) * BLOCK_SIZE,
                                     (float) (rand() % GAME_HEIGHT) * BLOCK_SIZE};
    block.setPosition(newApplePosition);
}

sf::Vector2f Apple::getPosition() {
    return block.getPosition();
}