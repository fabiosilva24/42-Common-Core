/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:28:26 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/06 20:28:28 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void initialize_philovalor(t_simulation *sim, int i)
{
    sim->philosophers[i].id = i + 1;
    sim->philosophers[i].simulation = sim;
    sim->philosophers[i].left_fork = i;
    sim->philosophers[i].right_fork = (i + 1) % sim->num_philosophers;
    sim->philosophers[i].meals_eaten = 0;
    sim->philosophers[i].last_meal_time = get_time_ms();
}


int 	init_simulation(void *arg)
{
    t_simulation *sim = (t_simulation *)arg;
    int i;

    i = 0;
	sim->philosophers = malloc(sizeof(t_philosopher) * sim->num_philosophers);
    if (!sim->philosophers)
        return (1);
    sim->forks = malloc(sizeof(pthread_mutex_t) * sim->num_philosophers);
    if (!sim->forks)
    {
        free(sim->philosophers);
        return (1);
    }
    pthread_mutex_init(&sim->print_mutex, NULL);
    pthread_mutex_init(&sim->death_mutex, NULL);
    while (i < sim->num_philosophers)
    {
        pthread_mutex_init(&sim->forks[i], NULL);
        i++;
    }
    i = 0;
    while (i < sim->num_philosophers)
    {
        initialize_philovalor(sim, i);
        i++;
    }
    return (0);
} 