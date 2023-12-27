#include "WinGameScreen.h"

WinGameScreen::WinGameScreen() {
    texture.loadFromFile("../res/victory.png");
    block.setTexture(texture);
    block.setPosition(0, 175);
}