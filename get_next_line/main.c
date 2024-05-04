#include "get_next_line.h"

#include <stdio.h>	// FILE, fopen()
#include <stdio.h> // printf()
#include <stdlib.h> // free()

char	*g_file_name = "bencao.txt";
FILE	*g_fp;

char	*get_next_line(int fd);

int main()

{
	char	*linha;
	int		i = 0;

	g_fp = fopen(g_file_name, "r");
	
	while((linha = get_next_line(g_fp->_fileno)) != NULL)
	{
		printf("Line %i >>> %s", i++, linha);
		free(linha);
	}
	
	fclose(g_fp);
	return (0);
}
