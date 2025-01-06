#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_simualation t_simulation;

typedef struct s_philosopher
{
	int					id;
	int					meals_eaten;
	int					left_fork;
	int					right_fork;

	pthread_t			thread;
	t_simulation		*simulation;
	long long			last_meal_time;
	long long			start_time;
} t_philosopher;


typedef struct s_simulation
{
	int					num_philosophers;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					max_meals;
	int					end_simulation;

	pthread_mutex_t 	*forks;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t 	death_mutex;
	t_philosopher             *philosophers;

	
} t_simulation;


void 	*init_simulation(void *arg);
void 	*philo_routine(void *arg);
void join_threads(t_simulation *sim);
void create_threads(t_simulation *sim);
void initialize_philovalor(t_simulation *sim, int i);


//utils
int ft_atoi(char *str);
long long get_time_ms(void);
int ft_usleep(size_t millisecounds);
int parse_input(t_simulation *sim, int argc, char **argv);

#endif