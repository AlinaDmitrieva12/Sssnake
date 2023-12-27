#include "Map.h"

Map::Map() {
    texture.loadFromFile("../res/tile.png");
    block.setTexture(texture);
}

void Map::draw(sf::RenderWindow &window) {
    for (int i = 0; i < GAME_WIDTH; i++)
        for (int j = 0; j < GAME_HEIGHT; j++) {
            block.setPosition(i * BLOCK_SIZE, j * BLOCK_SIZE);
            window.draw(block);
        }
}