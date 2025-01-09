#include "../include/philo.h"

void cleanup_simulation(t_simulation *sim)
{
    int i;
    
    i = 0;
    while (i++ < sim->num_philosophers)
    {
        pthread_mutex_destroy(&sim->forks[i]);
    }
    pthread_mutex_destroy(&sim->print_mutex);
    pthread_mutex_destroy(&sim->death_mutex);
    free(sim->forks);
    free(sim->philosophers);
}