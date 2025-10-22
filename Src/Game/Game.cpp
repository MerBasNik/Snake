#include "../Game/Game.h"
#include "../Graphics/Graphics.h"
#include <iostream>

Game::Game()
{
    isRunning = true;
    gameOver = false;
    gameWon = false;
    apple.Create(snake.GetBody());
}

//TODO в константу сообщение и вынести в отдельный метод
void Game::RunGame()
{
    if (!graphics.Initialize())
    {
        std::cout << "Failed to initialize graphics!" << std::endl;
        return;
    }
    int inputKey;
    bool moved;
    while (isRunning && graphics.IsWindowOpen())
    {
        graphics.ProcessEvents();
        inputKey = graphics.GetInput();
        //можно исп-ть тд map
        switch (inputKey)
        {
            case EXIT:
                isRunning = false;
                break;
            case RESTART:
                InitializeGame();
                break;
            default:
                if (!gameOver && !gameWon) {
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