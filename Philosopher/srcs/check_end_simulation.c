#include "../include/philo.h"

int check_end_simulation(t_simulation *sim)
{
    int i;
    int end_simulation;

    i = 0;
    pthread_mutex_lock(&sim->death_mutex);
    while (i < sim->num_philosophers)
    {
        if (get_elapsed_time(sim) - sim->philosophers[i].last_meal_time > sim->time_to_die)
        {
            sim->end_simulation = 1;
            break ;
        }
        i++;
    }
    end_simulation = sim->end_simulation;
    pthread_mutex_unlock(&sim->death_mutex);
    return (end_simulation);
}