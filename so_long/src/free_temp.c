void free_temp(char **temp, int height)
{
	int i;

	i = -1;
	while (++i < height)
		free(temp[i]);
	free(temp);
}