#include <iostream>
#include "Snake.h"

Snake::Snake() {
    texture.loadFromFile("../res/snake.png");
}

void Snake::updateColors(int colorNumber) {
    if (colorNumber == 4) {
        texture.loadFromFile("../res/redSnakeTexture.png");
    } else if (colorNumber == 5) {
        texture.loadFromFile("../res/orangeSnakeTexture.png");
    } else if (colorNumber == 6) {
        texture.loadFromFile("../res/blueSnakeTexture.png");
    }
}

void Snake::update() {
    headPosition = blocks[0].getPosition();
    for (int i = width; i > 0; i--) {
        sf::Vector2f oldBlock = blocks[i - 1].getPosition();
        blocks[i].setPosition(oldBlock);
    }
    sf::Vector2f movement(0, 0);
    if (dir == 0)
        movement.y += 1 * BLOCK_SIZE;
    if (dir == 1)
        movement.x -= 1 * BLOCK_SIZE;
    if (dir == 2)
        movement.x += 1 * BLOCK_SIZE;
    if (dir == 3)
        movement.y -= 1 * BLOCK_SIZE;
    blocks[0].move(movement);

    sf::Vector2f newHeadPosition = headPosition;
    bool changed = false;

    if (headPosition.x > GAME_WIDTH * BLOCK_SIZE) {
        newHeadPosition.x = 0;
        changed = true;
    }
    if (headPosition.x < 0) {
        newHeadPosition.x = GAME_WIDTH * BLOCK_SIZE;
        changed = true;
    }
    if (headPosition.y > GAME_HEIGHT * BLOCK_SIZE) {
        newHeadPosition.y = 0;
        changed = true;
    }
    if (headPosition.y < 0) {
        newHeadPosition.y = GAME_HEIGHT * BLOCK_SIZE;
        changed = true;
    }
    if (changed) {
        blocks[0].setPosition(newHeadPosition);
    }
}


void Snake::updateDirection() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        dir = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        dir = 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        dir = 3;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        dir = 0;
}

void Snake::draw(sf::RenderWindow &window, bool isLose) {
    for (int i = 0; i < width; i++) {
        blocks[i].setTexture(texture);
        if (i != 0)
            blocks[i].setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
        else
            blocks[i].setTextureRect(sf::IntRect(dir * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE));

        if (isLose && i == 1)
            blocks[i].setTextureRect(sf::IntRect(dir * BLOCK_SIZE, BLOCK_SIZE * 2, BLOCK_SIZE, BLOCK_SIZE));

        window.draw(blocks[i]);
    }
}

bool Snake::checkLose() {
    headPosition = blocks[0].getPosition();
    for (int i = 1; i < width; i++) {
        sf::Vector2f bodyPosition = blocks[i].getPosition();
        if ((headPosition.x == bodyPosition.x) && (headPosition.y == bodyPosition.y)) {
            return true;
        }
    }
    return false;
}

bool Snake::checkAppleCollision(const sf::Vector2f &applePosition) {
    if ((headPosition.x == applePosition.x) && (headPosition.y == applePosition.y)) {
        width++;
        return true;
    }
    return false;
}

bool Snake::checkOrangeCollision(const sf::Vector2f &orangePosition) {
    if ((headPosition.x == orangePosition.x) && (headPosition.y == orangePosition.y)) {
        width += 2;
        return true;
    }
    return false;

}

bool Snake::checkSpeedUpCollision(const sf::Vector2f &speedUpPosition) const {
    return (headPosition.x == speedUpPosition.x) && (headPosition.y == speedUpPosition.y);
}

bool Snake::checkSpeedDownCollision(const sf::Vector2f &speedDownPosition) const {
    return (headPosition.x == speedDownPosition.x) && (headPosition.y == speedDownPosition.y);
}