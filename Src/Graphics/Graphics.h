#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <deque>
#include <utility>

class Graphics
{
public:
    Graphics();
    void PrintResult(bool gameWon, bool gameOver);
    bool Initialize(int score);
    void Render(const std::deque<std::pair<int, int>>& snakeBody, const std::pair<int, int> &applePos, int score);
    void Close();
    bool IsWindowOpen();
    void ProcessEvents();

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text scoreText;
    int lastKeyPressed;
    static const int CELL_SIZE = 32;
    static const int FIELD_WIDTH = 20;
    static const int FIELD_HEIGHT = 10;
    static const int WINDOW_WIDTH = FIELD_WIDTH * CELL_SIZE;
    static const int WINDOW_HEIGHT = FIELD_HEIGHT * CELL_SIZE;
    const sf::Color SNAKE_HEAD_COLOR = sf::Color::Green;
    const sf::Color SNAKE_TAIL_COLOR = sf::Color(0, 140, 0);
    const sf::Color APPLE_COLOR = sf::Color::Red;
    const sf::Color BORDER_COLOR = sf::Color::Blue;
    const sf::Color WINDOW_COLOR = sf::Color::Black;
    const std::string ERROR_MSG = "Шрифт не найден. Положите arial.ttf в папку с игрой.";
    const std::string WIN_MSG = "You Win!";
    const std::string GAME_OVER_MSG = "Game Over!";
    const std::string END_MSG = "Press R to restart or ESC to exit";
    void CheckInit();
    void DrawApple(const std::pair<int, int> &applePos, sf::Color appleColor);
    void DrawSnake(const std::deque<std::pair<int, int>> &snakeBody, sf::Color headColor, sf::Color tailColor);
    void DrawBorder(sf::Color borderColor);
    int GetInput();
    sf::Vector2f GridToPixel(const std::pair<int, int> &gridPos);
    int SetDirection(std::optional<sf::Event> event);
    void PrintMessage(std::string msg, int size, sf::Color color, sf::Vector2f pos);
};
