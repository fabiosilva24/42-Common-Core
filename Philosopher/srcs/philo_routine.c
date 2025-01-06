/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:46:13 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/06 20:38:13 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *philo_routine(void *arg)
{
    t_philosopher *philo = (t_philosopher *)arg;

    while(1)
    {
        if (philo->simulation->end_simulation)
            break;
        philo_eat(philo);
        philo_thinking(philo);
        philo_sleep(philo);
    }
    return (NULL);
}

void *monitor_philos(void *arg)
{
    t_simulation *sim = (t_simulation *)arg;
    int i;
    
    while(1)
    {
        i = 0;
        while (i < sim->num_philosophers)
        {
            pthread_mutex_lock(&sim->death_mutex);
            if (get_time_ms () - sim->philosophers[i].last_meal_time > sim->time_to_die)
            {
                pthread_mutex_lock(&sim->print_mutex);
                printf("Philosopher %d died\n", sim->philosophers[i].id);
                sim->end_simulation = 1;
                pthread_mutex_unlock(&sim->print_mutex);
                pthread_mutex_unlock(&sim->death_mutex);
                return (NULL);
            }
            pthread_mutex_unlock(&sim->death_mutex);
            i++;
        }
        ft_usleep(100);
    }
    return (NULL);
}

void create_threads(t_simulation *sim)
{
    int i;

    i = 0;
    if (sim->num_philosophers == 1)
    {
        if (pthread_create(&sim->philosophers[0].thread, NULL, philo_routine, (void *)&sim->philosophers[0]) != 0)
        {
            printf("Error creating thread for 1 philosopher :( \n");
            exit(EXIT_FAILURE);
        }
    }
    pthread_t monitor_thread;
    if (pthread_create(&monitor_thread, NULL, monitor_philos, (void *)sim) != 0)
    {
        printf("Error creating monitor thread\n");
        exit(EXIT_FAILURE);
    }
    while (i < sim->num_philosophers)
    {
        if (pthread_create(&sim->philosophers[i].thread, NULL, philo_routine, (void *)&sim->philosophers[i]) != 0)
        {
            printf("Error creating thread for philosopher %d :( \n", i + 1);
            exit(EXIT_FAILURE);
        }
        i++;
    }
    pthread_join(monitor_thread, NULL);
}

void join_threads(t_simulation *sim)
{
    int i;

    i = 0;

    while (i < sim->num_philosophers)
    {
        if (pthread_join(sim->philosophers[i].thread, NULL) != 0)
        {
            printf("Error joining thread for philosopher %d :( \n", i);
            exit(EXIT_FAILURE);
        }
        i++;
    }
}