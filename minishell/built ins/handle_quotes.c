void double_quotes(char *symbol)
{
	int len;
	int i;
	
	len = strlen(symbol);
	i = 1;
	if (symbol[0] == '\"')
	{
		while (i < len - 1)
		{
			if (symbol[i] == '\n')
				printf("\\n");
			else if (symbol[i] == '\t')
				printf("\\t");
			else if (symbol[i] == '$')
				handle_dollarsign(symbol, &i, len);
			else if (ft_isprint(symbol[i]))
				printf("%c", symbol[i]);
			else
				printf("\\x%02x", symbol[i]);
			i++;
		}
	}
}

void handle_dollarsign(char *symbol, int *i, int len)
{
	const char *user;
	user = getenv("USER");
	if (*i + 1 < len - 1)
	{
		if (symbol[*i + 1] == 'U' && symbol[*i + 2] == 'S' && symbol[*i + 3] == 'E' && symbol[*i + 4] == 'R')
		{
			if (user)
				printf("%s", user);
			else
				printf("User not set");
			*i += 4;
		}
		else
			printf("$");
	}
}