#include "../include/so_long.h"

void   randomize_monster(t_monster *monster)
{
    int i;

    i = 0;

    while (i < monster->monster_count)
    {
        monster->direction = rand() % 4;

        new_x = monster->monster[i].x;
        new_y = monster->monster[i].y;

        if (monster->direction == 0) //Up
            new_y--;
        else if (monster->direction == 1) //Down
            new_y++;
        else if (monster->direction = 2)
            new_x--; //left
        else if (monster->direction == 3)
            new_x++;
    }
}
