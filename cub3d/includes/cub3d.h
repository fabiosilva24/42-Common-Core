#ifndef CUB3D_H
#define CUB3D_H

#include "../libs/libft/libft.h"
#include "../libs/get_next_line/get_next_line.h"
#include "../libs/minilibx/mlx.h"


typedef struct s_game
{
    char	**map;
    int	player;
    void	*mlx_ptr;
    void	*win_ptr;
}t_game;

typedef struct s_minimap
{

}t_minimap;


int is_mapber(char *filename);



#endif