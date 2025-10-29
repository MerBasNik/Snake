#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#pragma once
#include <map>

#include "../Field/Field.h"
#include "../Apple/Apple.h"
#include "../Snake/Snake.h"
#include "../Graphics/Graphics.h"

const int FIELD_WIDTH = 20;
const int FIELD_HEIGHT = 10;
const int START_X = FIELD_WIDTH / 2;
const int START_Y = FIELD_HEIGHT / 2;
const int COUNT_X = FIELD_WIDTH - 2;
const int COUNT_Y = FIELD_HEIGHT - 2;
const int DELAY_MS = 250;
const std::string ERROR_MSG = "Failed to initialize graphics!";

class Game
{
public:
    Game();
    void RunGame();
private:
    Graphics graphics;
    Field field;
    Apple apple;
    Snake snake;

    bool isRunning;
    bool gameOver;
    bool gameWon;

    std::unordered_map<int, std::function<void()>> InitMapSpecialKeys();
    void CheckGraphicInit();
    void Render();
    void InitializeGame();
};


#endif //SNAKE_GAME_H