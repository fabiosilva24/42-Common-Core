#include "../include/philo.h"

int check_end_simulation(t_simulation *sim)
{
    int end_simulation;

    pthread_mutex_lock(&sim->death_mutex);
    end_simulation = sim->end_simulation;
    pthread_mutex_unlock(&sim->death_mutex);
    return (end_simulation);
}