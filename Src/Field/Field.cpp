#include "../Field/Field.h"
#include <iostream>
#include <vector>
#include "../Snake/Snake.h"
#include "../Game/Game.h"

Field::Field()
{
    field = Init();
    field = SetFieldBorder(field);
}

std::vector<std::vector<char>> Field::Init()
{
    return std::vector<std::vector<char>>(FIELD_HEIGHT, std::vector<char>(FIELD_WIDTH, CELL_FIELD));
}

void Field::Clear()
{
    for (int y = 1; y < FIELD_HEIGHT - 1; y++)
    {
        for (int x = 1; x < FIELD_WIDTH - 1; x++)
        {
            field[y][x] = CELL_FIELD;
        }
    }
}

std::vector<std::vector<char>> Field::SetFieldBorder(const std::vector<std::vector<char>> &cleanField)
{
    std::vector<std::vector<char>> renderField = cleanField;
    renderField[0].assign(FIELD_WIDTH, UP_DOWN_BORDER);
    renderField[FIELD_HEIGHT - 1].assign(FIELD_WIDTH, UP_DOWN_BORDER);
    for (int y = 1; y < FIELD_HEIGHT - 1; y++)
    {
        renderField[y][0] = LEFT_RIGHT_BORDER;
        renderField[y][FIELD_WIDTH - 1] = LEFT_RIGHT_BORDER;
    }
    return renderField;
}

void Field::Render(Snake &snake)
{
    system("clear");
    field = SetFieldBorder(field);
    std::cout << "Очки: " << snake.GetTotal() << std::endl;
    for (int y = 0; y < FIELD_HEIGHT; y++)
    {
        for (int x = 0; x < FIELD_WIDTH; x++)
        {
            std::cout << field[y][x];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
