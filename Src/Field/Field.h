#ifndef SNAKE_FIELD_H
#define SNAKE_FIELD_H
#include <vector>
#include "../Snake/Snake.h"
const char UP_DOWN_BORDER = '-';
const char LEFT_RIGHT_BORDER = '|';
const char CELL_FIELD = ' ';

class Field
{
public:
    std::vector<std::vector<char>> field;
    Field();
    // std::vector<std::vector<char>> SetFieldBorder(const std::vector<std::vector<char>> &cleanField);
    // void Clear();
    // void Render(Snake &total);
private:
    std::vector<std::vector<char>> Init();
};

#endif //SNAKE_FIELD_H