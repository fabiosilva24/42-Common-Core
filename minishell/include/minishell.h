#ifndef MINISHELL_H
#define MINISHELL_H

# include <readline/readline.h>     // readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history
# include <stdio.h>                 // printf, perror
# include <stdlib.h>                // malloc, free, exit
# include <unistd.h>                // write, access, fork, getcwd, chdir, unlink, dup, dup2, pipe, isatty, ttyname, ttyslot
# include <fcntl.h>                 // open
# include <sys/types.h>             // fork, wait, waitpid, wait3, wait4, stat, lstat, fstat
# include <sys/stat.h>              // stat, lstat, fstat
# include <sys/wait.h>              // wait, waitpid, wait3, wait4
# include <signal.h>                // signal, sigaction, sigemptyset, sigaddset, kill
# include <dirent.h>                // opendir, readdir, closedir
# include <string.h>                // strerror
# include <termios.h>               // tcsetattr, tcgetattr
# include <curses.h>   // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <sys/ioctl.h>             // ioctl
# include <errno.h>                 // strerror (alternative for error strings)

extern char **environ;

typedef struct s_minishell
{
    char **environment;

}t_minishell;

void	print_banner();
void    double_quotes(char *symbol);
char    **get_environment(void);
void    single_quotes(char *symbol);



#endif