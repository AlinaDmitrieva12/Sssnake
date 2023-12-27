#include "LoseGameScreen.h"

LoseGameScreen::LoseGameScreen() {
    texture.loadFromFile("../res/gameover.png");
    block.setTexture(texture);
    block.setPosition(0, 175);
}