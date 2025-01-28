#include "../include/minishell.h"

static void handle_dollarsign(char *symbol, int *i, int len)
{
	char var_name[256] = {0};
	int j;
	
	char *value = getenv(var_name);
	j = 0;

	(*i)++;
	while (*i < len && (isalnum(symbol[*i]) || symbol[*i] == '_'))
	{
		if (j < 255)
		{
			var_name[j++] = symbol[*i];
		}
		(*i)++;
	}
	var_name[j] = '\0';
	if (value)
	{
		printf("%s", value);
	}
	else
	{
		printf("$%s", var_name);
	}
	(*i)--;
}

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
			else if (isprint(symbol[i]))
				printf("%c", symbol[i]);
			else
				printf("\\x%02x", symbol[i]);
			i++;
		}
	}
	printf("\n");
}