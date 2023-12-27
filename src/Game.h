#ifndef _GAME_H_
#define _GAME_H_

#include "Snake.h"
#include "Apple.h"
#include "Orange.h"
#include "SpeedUp.h"
#include "SpeedDown.h"
#include "Map.h"
#include "WinGameScreen.h"
#include "LoseGameScreen.h"
#include "MainMenu.h"
#include "CustomizationMenu.h"
#include <SFML/Audio.hpp>

const float SPEED_UP_DURATION = 5;
const float SPEED_UP_COOLDOWN = 5;
const float SPEED_DOWN_DURATION = 8;
const float SPEED_DOWN_COOLDOWN = 8;
enum GAME_STATE {
        MENU,
        PLAY,
        CUSTOMIZATION
};

class Game {
public:
    Snake snake;
    Apple apple;
    Orange orange;
    SpeedUp speedUp;
    SpeedDown speedDown;
    Map map;
    WinGameScreen winGameScreen;
    LoseGameScreen loseGameScreen;
    sf::RenderWindow &window;
    sf::Music music;
    MainMenu mainMenu;
    CustomizationMenu customizationMenu;
    GAME_STATE gameState = GAME_STATE::MENU;


    explicit Game(sf::RenderWindow &window);

    bool game = true;
    float timer = 0;
    float speedUpDuration = 0;
    float speedUpCooldown = 0;
    bool isSpeedUpOnCooldown = true;
    bool isSpeedUpActive = false;
    float speedDownDuration = 0;
    float speedDownCooldown = 0;
    bool isSpeedDownOnCooldown = true;
    bool isSpeedDownActive = false;
    float delay = 0.4;

    void play();

    void update(sf::Clock &clock);

    void handleEvents();

    void customizeWindow();

    void render();
};

#endif //_GAME_H_
