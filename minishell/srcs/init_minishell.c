#include "../include/minishell.h"

void init_minishell(t_minishell *shell)
{
    shell->environment = getenv("PATH");
}