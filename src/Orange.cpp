#include "Orange.h"

Orange::Orange() {
    texture.loadFromFile("../res/orange.png");
    block.setTexture(texture);
    sf::Vector2f initialOrangePosition = {5 * BLOCK_SIZE, 15 * BLOCK_SIZE};
    block.setPosition(initialOrangePosition);
}

void Orange::updatePosition() {
    sf::Vector2f newOrangePosition = {(float) (rand() % GAME_WIDTH) * BLOCK_SIZE,
                                      (float) (rand() % GAME_HEIGHT) * BLOCK_SIZE};
    block.setPosition(newOrangePosition);
}

sf::Vector2f Orange::getPosition() {
    return block.getPosition();
}