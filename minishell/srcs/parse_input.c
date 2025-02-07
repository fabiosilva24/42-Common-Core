#include "../include/minishell.h"

void	parse_input(char *input)
{
	char *arg = input;
	int handled = 0;

	while (*arg)
	{
		if (*arg == '\"')
		{
			double_quotes(arg);
			handled = 1;
			break;
		}
		else if (*arg == '\'')
		{
			single_quotes(arg);
			handled = 1;
			break;
		}
		arg++;
	}

	if (!handled)
	{
		printf("%s", input);
	}
}