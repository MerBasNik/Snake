#include "Snake.h"
#include <iostream>
#include "../Game/Game.h"

Snake::Snake()
{
    body = InitBody(START_X, START_Y);
}

std::deque<std::pair<int, int>> Snake::InitBody(int x, int y)
{
    std::deque<std::pair<int, int>> initBody;
    initBody.push_back(std::make_pair(x, y));
    initBody.push_back(std::make_pair(x, y + 1));
    return initBody;
}

std::pair<int, int> Snake::CalcNewPosition(int dir, const std::pair<int, int> &pos)
{
    int x = pos.first;
    int y = pos.second;
    if (dir != 0 && IsValidDirection(dir))
    {
        return ApplyDirection(dir, x, y);
    }
    return ApplyDirection(direction, x, y);
}

bool Snake::IsValidDirection(int dir)
{
    switch (dir)
    {
        case UP_DIR: return direction != DOWN_DIR;
        case LEFT_DIR: return direction != RIGHT_DIR;
        case RIGHT_DIR: return direction != LEFT_DIR;
        case DOWN_DIR: return direction != UP_DIR;
        default: return false;
    }
}

std::pair<int, int> Snake::ApplyDirection(int dir, int x, int y)
{
    switch (dir)
    {
        case UP_DIR: return {x, y - 1};
        case LEFT_DIR: return {x - 1, y};
        case RIGHT_DIR: return {x + 1, y};
        case DOWN_DIR: return {x, y + 1};
        default: return {x, y};
    }
}


bool Snake::Move(int dir, Apple &apple)
{
    auto oldBody = body;
    auto newHeadPos = CalcNewPosition(dir, body.front());
    if (dir != 0 && IsValidDirection(dir))
    {
        direction = dir;
    }
    Eat(apple, newHeadPos, oldBody);
    auto newBody = CreateNewBody(newHeadPos);
    body = newBody;
    if (CheckCollision())
    {
        body = oldBody;
        return false;
    }
    return true;
}

std::deque<std::pair<int, int>> Snake::CreateNewBody(const std::pair<int, int> &newHead)
{
    auto newBody = body;
    newBody.push_front(newHead);
    newBody.pop_back();
    return newBody;
}

void Snake::Eat(Apple &apple, const std::pair<int, int> &newHead, const std::deque<std::pair<int, int>> &oldBody)
{
    if (IsAppleEaten(apple, newHead))
    {
        total++;
        body = Increase(oldBody);
        apple.Create(body);
    }
}

bool Snake::IsAppleEaten(Apple &apple, const std::pair<int, int> &newHead)
{
    std::pair<int, int> pos = apple.GetPos();
    return newHead.first == pos.first && newHead.second == pos.second;
}

std::deque<std::pair<int, int>> Snake::Increase(const std::deque<std::pair<int, int>> &currentBody)
{
    if (currentBody.empty())
    {
        return currentBody;
    }
    auto newBody = currentBody;
    const auto &lastSegment = newBody.back();
    auto newSegment = CalcNewSegmentPos(lastSegment);
    newBody.push_back(newSegment);
    return newBody;
}

std::pair<int, int> Snake::CalcNewSegmentPos(const std::pair<int, int> &lastSegment)
{
    auto segment = lastSegment;
    int x = segment.first, y = segment.second;
    switch (direction)
    {
        case UP_DIR: return {x, y + 1};
        case LEFT_DIR: return {x + 1, y};
        case RIGHT_DIR: return {x - 1, y};
        case DOWN_DIR: return {x, y - 1};
        default: return {x, y};
    }
}

bool Snake::IsWin()
{
    int maxScore = COUNT_X * COUNT_Y;
    return total >= maxScore;
}

bool Snake::CheckCollision()
{
    return CheckSelfCollision() || CheckWallCollision();
}

bool Snake::CheckSelfCollision()
{
    if (body.empty()) return false;
    const auto &head = body.front();
    for (int i = 1; i < body.size(); i++)
    {
        if (head.first == body[i].first && head.second == body[i].second)
        {
            return true;
        }
    }
    return false;
}

bool Snake::CheckWallCollision()
{
    if (body.empty()) return false;
    if (body[0].first <= 0 || body[0].first >= (FIELD_WIDTH - 1) ||
        body[0].second <= 0 || body[0].second >= (FIELD_HEIGHT - 1))
    {
        return true;
    }
    return false;
}

std::deque<std::pair<int, int>> Snake::GetBody()
{
    return body;
}

int Snake::GetTotal()
{
    return total;
}

// int Snake::KeyToDirection(char key)
// {
//     switch (key)
//     {
//         case UP_KEY: return UP_DIR;
//         case DOWN_KEY: return DOWN_DIR;
//         case LEFT_KEY: return LEFT_DIR;
//         case RIGHT_KEY: return RIGHT_DIR;
//         case EXIT_KEY: return EXIT;
//         default: return 0;
//     }
// }
// int Snake::GetDirection()
// {
//     char ch = getchar();
//     return KeyToDirection(ch);
// }
// void Snake::DrawSnake(std::vector<std::vector<char>> &field)
// {
//     DrawHead(field);
//     DrawTail(field);
// }
//
// void Snake::DrawHead(std::vector<std::vector<char>> &field)
// {
//     if (!body.empty())
//     {
//         field[body[0].second][body[0].first] = SNAKE_HEAD;
//     }
// }
//
// void Snake::DrawTail(std::vector<std::vector<char>> &field)
// {
//     for (int i = 1; i < body.size(); i++)
//     {
//         field[body[i].second][body[i].first] = SNAKE_TAIL;
//     }
// }
