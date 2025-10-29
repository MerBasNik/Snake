#include "../Game/Game.h"
#include "../Graphics/Graphics.h"
#include <iostream>
#include <map>

Game::Game()
{
    isRunning = true;
    gameOver = false;
    gameWon = false;
    apple.Create(snake.GetBody());
}

void Game::CheckGraphicInit()
{
    if (!graphics.Initialize(snake.GetTotal()))
    {
        std::cout << ERROR_MSG << std::endl;
    }
}

std::unordered_map<int, std::function<void()>> Game::InitMapSpecialKeys()
{
    return {
        {EXIT, [this]() {isRunning = false;}},
        {RESTART, [this]() {InitializeGame();}},
    };
}

void Game::RunGame()
{
    CheckGraphicInit();
    int inputKey;
    bool moved;
    std::unordered_map<int, std::function<void()>> specialKeys = InitMapSpecialKeys();
    while (isRunning && graphics.IsWindowOpen())
    {
        graphics.ProcessEvents();
        inputKey = graphics.GetInput();
        auto it = specialKeys.find(inputKey);
        if (it != specialKeys.end())
        {
            it->second();
        } else {
            if (!gameOver && !gameWon)
            {
                moved = snake.Move(inputKey, apple);
                if (!moved)
                {
                    gameOver = true;
                }
                gameWon = snake.IsWin();
                Render();
            } else {
                graphics.PrintResult(gameWon, gameOver);
            }
        }
        sf::sleep(sf::milliseconds(DELAY_MS));
    }
    graphics.Close();
}

void Game::Render()
{
    graphics.Render(snake.GetBody(), apple.GetPos(), snake.GetTotal());
}

void Game::InitializeGame()
{
    snake = Snake();
    apple.Create(snake.GetBody());
    gameOver = false;
    gameWon = false;
    isRunning = true;
}