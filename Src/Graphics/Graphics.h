#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <deque>
#include <utility>



class Graphics
{
public:
    Graphics();
    void DrawApple(const std::pair<int, int> &applePos);
    void DrawSnake(const std::deque<std::pair<int, int>> &snakeBody);
    void DrawBorder();
    void PrintResult(bool gameWon, bool gameOver);
    int SetDiraction(std::optional<sf::Event> event);
    void PrintMessage(std::string msg, int size, sf::Color color, sf::Vector2f pos);
    bool Initialize();
    void Render(const std::deque<std::pair<int, int>>& snakeBody, const std::pair<int, int> &applePos, int score);
    void Close();
    bool IsWindowOpen();
    void ProcessEvents();
    int GetInput();
    sf::Vector2f GridToPixel(const std::pair<int, int> &gridPos);
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
};
