/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:46:13 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/12/05 18:46:13 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void 	*philo_routine(void *arg)
{
    int i = 0;
	sim->philosophers = malloc(sizeof(t_philo) * sim->num_philosophers);
    if (!sim->philosophers)
        return (1);
    sim->forks = malloc(sizeof(pthread_mutex_t) * sim->num_philosophers);
    if (!sim->forks)
        return (1);
    pthread_mutex_init(&sim->print_mutex, NULL);
    while (i < sim->num_philosophers)
    {
        pthread_mutex-init(&sim->forks[i], NULL);
        i++;
    }
    i = 0;
    while (i < sim->num_philosophers)
    {
        sim->philosophers[i].id = i + 1;
        sim->philosophers[i].simulation = sim;
        sim->philosophers[i].left_fork = i;
        sim->philosophers[i].right_fork = (i + 1) % sim->philosophers;
        sim->philosophers[i].meals_eaten = 0;
        sim->philosophers[i].last_meal_time = get_time_ms();
        i++;
    }
}
