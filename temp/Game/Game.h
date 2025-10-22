#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H
#include "../Field/Field.h"
#include "../Apple/Apple.h"
#include "../Snake/Snake.h"

const int DELAY_MCS = 300000;

class Game
{
private:
    void SetNonBlocking(bool enable);
    void Render(Field &field, Apple &apple, Snake &snake);
    bool GameLoop(Field &field, Apple &apple, Snake &snake);
public:
    bool Run();
};


#endif //SNAKE_GAME_H