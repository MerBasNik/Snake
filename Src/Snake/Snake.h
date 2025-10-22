#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#include <deque>
#include <utility>
#include "../Apple/Apple.h"

static constexpr int UP_DIR = 1;
static constexpr int DOWN_DIR = 2;
static constexpr int LEFT_DIR = 3;
static constexpr int RIGHT_DIR = 4;
static constexpr int RESTART = 5;
static constexpr int EXIT = -1;

static constexpr char SNAKE_HEAD = '&';
static constexpr char SNAKE_TAIL = 'o';
static constexpr char APPLE = '@';
static constexpr char UP_KEY = 'w';
static constexpr char LEFT_KEY = 'a';
static constexpr char DOWN_KEY = 's';
static constexpr char RIGHT_KEY = 'd';
static constexpr char EXIT_KEY = 'q';

class Snake
{
public:
    Snake();
    std::deque<std::pair<int, int>> InitBody(int x, int y);
    void DrawSnake(std::vector<std::vector<char>> &field);
    bool Move(int dir, Apple &apple);
    bool IsWin();
    bool CheckCollision();
    int GetDirection();
    int GetTotal();
    std::deque<std::pair<int, int>> GetBody();
private:
    std::deque<std::pair<int, int>> body;
    int direction = UP_DIR;
    int total = 0;

    std::pair<int, int> CalcNewPosition(int dir, const std::pair<int, int> &pos);
    bool IsValidDirection(int dir);
    std::pair<int, int> ApplyDirection(int dir, int x, int y);
    std::deque<std::pair<int, int>> CreateNewBody(const std::pair<int, int> &newHead);
    bool IsAppleEaten(Apple &apple, const std::pair<int, int> &newHead);
    std::deque<std::pair<int, int>> Increase(const std::deque<std::pair<int, int>> &currentBody);
    std::pair<int, int> CalcNewSegmentPos(const std::pair<int, int> &lastSegment);
    int KeyToDirection(char key);
    void DrawHead(std::vector<std::vector<char>> &field);
    void DrawTail(std::vector<std::vector<char>> &field);
    void Eat(Apple &apple, const std::pair<int, int> &newHead, const std::deque<std::pair<int, int>> &oldBody);
    bool CheckWallCollision();
    bool CheckSelfCollision();
};


#endif //SNAKE_SNAKE_H