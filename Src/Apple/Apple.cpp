#include "../Apple/Apple.h"
#include <utility>
#include "../Game/Game.h"

Apple::Apple() : engine(device())
{
}

std::pair<int, int> Apple::GetPos()
{
    return pos;
}

std::pair<int, int> Apple::GeneratePosition()
{
    std::uniform_int_distribution distX(1, COUNT_X);
    std::uniform_int_distribution distY(1, COUNT_Y);
    int x, y;
    x = distX(engine);
    y = distY(engine);
    return {x, y};
}

void Apple::Create(std::deque<std::pair<int, int>> snake)
{
    std::pair<int, int> applePos = GeneratePosition();
    for (int i = 0; i < snake.size(); i++)
    {
        if (snake[i].first == applePos.first && snake[i].second == applePos.second)
        {
            applePos = GeneratePosition();
            i = 0;
        }
    }
    pos = applePos;
}
//
// void Apple::DrawApple(std::vector<std::vector<char>> &field)
// {
//     field[pos.second][pos.first] = APPLE;
// };
