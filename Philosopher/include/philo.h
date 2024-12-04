#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>




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

	long long			start_time;
} t_simulation;

typedef struct s_philo
{
	int					id;
	int					meals_eaten;
	int					left_forks_id;
	int					right_forks_id;

	pthread_t			thread;
	t_simulation		*simulation;
	long long			last_meal_time;
}

int		init_simulation(t_simulation *sim, int argc, char **argv);
void 	*philo_routine(void *arg);



#endif