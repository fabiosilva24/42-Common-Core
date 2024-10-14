#include "../include/so_long.h"

int is_rectangle(t_game *game, int num_rows)
{
	int row_len;
	int i;
	
	row_len = ft_strlen(map[0]);
	i = 1;
	while (i < num_rows)
	{
		if (ft_strlen(map[i]) != row_len)
		{
			ft_printf("Map is not rectangle\n");
			return 0;
		i++;
		}
	}
	return 1;
}
		
	




