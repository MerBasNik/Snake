#include "Graphics.h"
#include "../Game/Game.h"
#include <iostream>

Graphics::Graphics() :
    window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Snake"),
    scoreText(font, "", 24),
    lastKeyPressed(0)
{
}

bool Graphics::Initialize()
{
    if (!font.openFromFile("arial.ttf"))
    {
        std::cout << "Шрифт не найден. Положите arial.ttf в папку с игрой." << std::endl;
        return false;
    }
    scoreText = sf::Text(font, "Score: 0", 24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition({CELL_SIZE, CELL_SIZE - 24});
    window.setFramerateLimit(60);
    return true;
}

void Graphics::Render(const std::deque<std::pair<int, int>>& snakeBody, const std::pair<int, int> &applePos, int score)
{
    window.clear(sf::Color::Black);

    DrawBorder();
    DrawApple(applePos);
    DrawSnake(snakeBody);

    scoreText.setString("Score: " + std::to_string(score));
    window.draw(scoreText);
    window.display();
}

void Graphics::DrawBorder()
{
    sf::RectangleShape wall(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    wall.setFillColor(sf::Color::Blue);

    for (int x = 0; x < FIELD_WIDTH; x++)
    {
        wall.setPosition(GridToPixel({x, 0}));
        window.draw(wall);
        wall.setPosition(GridToPixel({x, FIELD_HEIGHT - 1}));
        window.draw(wall);
    }

    for (int y = 1; y < FIELD_HEIGHT - 1; y++)
    {
        wall.setPosition(GridToPixel({0, y}));
        window.draw(wall);
        wall.setPosition(GridToPixel({FIELD_WIDTH - 1, y}));
        window.draw(wall);
    }
}

void Graphics::DrawApple(const std::pair<int, int> &applePos)
{
    sf::CircleShape appleShape(CELL_SIZE / 2);
    appleShape.setFillColor(sf::Color::Red);
    appleShape.setPosition(GridToPixel(applePos));
    window.draw(appleShape);
}

void Graphics::DrawSnake(const std::deque<std::pair<int, int>> &snakeBody)
{
    //TODO вынести в константы цвета
    if (!snakeBody.empty())
    {
        sf::RectangleShape head(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));
        head.setFillColor(sf::Color::Green);
        head.setPosition(GridToPixel(snakeBody.front()));
        window.draw(head);

        sf::RectangleShape bodySegment(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));
        bodySegment.setFillColor(sf::Color(0, 140, 0));

        for (size_t i = 1; i < snakeBody.size(); i++)
        {
            bodySegment.setPosition(GridToPixel(snakeBody[i]));
            window.draw(bodySegment);
        }
    }
}

void Graphics::PrintResult(bool gameWon, bool gameOver)
{
    if (gameWon)
    {
        PrintMessage("You Win!", 36, sf::Color::Green, {WINDOW_WIDTH / 4.f, WINDOW_HEIGHT / 3.f});
    }
    if (gameOver)
    {
        PrintMessage("Game Over!", 36, sf::Color::Red, {WINDOW_WIDTH / 4.f, WINDOW_HEIGHT / 3.f});
    }
    PrintMessage("Press R to restart or ESC to exit", 20, sf::Color::White, {WINDOW_WIDTH / 4.f, WINDOW_HEIGHT / 2.f});
    window.display();
}

void Graphics::PrintMessage(std::string msg, int size, sf::Color color, sf::Vector2f pos)
{
    sf::Text message(font, msg, size);
    message.setFillColor(color);
    message.setPosition(pos);
    window.draw(message);
}

void Graphics::Close()
{
    window.close();
}

bool Graphics::IsWindowOpen()
{
    return window.isOpen();
}

void Graphics::ProcessEvents()
{
    lastKeyPressed = 0;
    while (std::optional<sf::Event> event = window.pollEvent())
    {
        if (event && event->is<sf::Event::Closed>())
        {
            window.close();
        }
        lastKeyPressed = SetDiraction(event);
    }
}

int Graphics::SetDiraction(std::optional<sf::Event> event)
{
    if (event && event->is<sf::Event::KeyPressed>())
    {
        auto keyEvent = event->getIf<sf::Event::KeyPressed>();
        if (keyEvent) {
            using enum sf::Keyboard::Key;

            switch (keyEvent->code)
            {
                case Up: case W: return UP_DIR;
                case Down: case S: return DOWN_DIR;
                case Left: case A: return LEFT_DIR;
                case Right: case D: return RIGHT_DIR;
                case Escape: return EXIT;
                case R: return RESTART;
                default: break;
            }
        }
    }
    return lastKeyPressed;
}

int Graphics::GetInput()
{
    return lastKeyPressed;
}

sf::Vector2f Graphics::GridToPixel(const std::pair<int, int> &gridPos)
{
    return sf::Vector2f(gridPos.first * CELL_SIZE, gridPos.second * CELL_SIZE);
}