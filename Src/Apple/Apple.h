#ifndef SNAKE_APPLE_H
#define SNAKE_APPLE_H
#include <deque>
#include <random>
#include <utility>

class Apple
{
public:
    Apple();
    std::pair<int, int> GetPos();
    void Create(std::deque<std::pair<int, int>> snake);
    // void DrawApple(std::vector<std::vector<char>> &field);
private:
    std::pair<int, int> pos;
    std::pair<int, int> GeneratePosition();
    std::random_device device;
    std::mt19937 engine;
};

#endif //SNAKE_APPLE_H