#include "./Game.h"
#include <ostream>
#include "../Field/Field.h"
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/termios.h>

void Game::SetNonBlocking(bool enable)
{
    static struct termios oldt, newt;
    if (enable)
    {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}

void Game::Render(Field &field, Apple &apple, Snake &snake)
{
    snake.DrawSnake(field.field);
    apple.DrawApple(field.field);
    field.Render(snake);
}

bool Game::GameLoop(Field &field, Apple &apple, Snake &snake)
{
    int dir;
    bool canMove;
    apple.Create(snake.GetBody());
    while (true)
    {
        dir = snake.GetDirection();
        if (dir == EXIT)
        {
            return false;
        }
        field.Clear();
        canMove = snake.Move(dir, apple);
        if (!canMove)
        {
            return false;
        }
        if (snake.IsWin())
        {
            return true;
        }
        Render(field, apple, snake);
        usleep(DELAY_MCS);
    }
}

bool Game::Run()
{
    SetNonBlocking(true);
    Field field;
    Apple apple;
    Snake snake;
    bool result = GameLoop(field, apple, snake);
    SetNonBlocking(false);
    return result;
}
