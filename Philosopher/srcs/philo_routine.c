/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:46:13 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/09 19:57:15 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *philo_routine(void *arg)
{
    t_philosopher *philo = (t_philosopher *)arg;
    while(1)
    {
        if (check_end_simulation(philo->simulation))
            break;
        philo_eat(philo);
        if (check_end_simulation(philo->simulation))
            break;
        philo_sleep(philo);
        if (check_end_simulation(philo->simulation))
            break;
        philo_thinking(philo);
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
            if (get_time_ms() - sim->philosophers[i].last_meal_time > sim->time_to_die)
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
        if (check_end_simulation(sim))
            break;
        ft_usleep(1000);
    }
    return (NULL);
}

void create_threads(t_simulation *sim)
{
    int i;
    pthread_t monitor_thread;
    
    i = 0;
    
    while (i < sim->num_philosophers)
    {
        if (pthread_create(&sim->philosophers[i].thread, NULL, philo_routine, (void *)&sim->philosophers[i]) != 0)
        {
            printf("Error creating thread for philosopher %d :( \n", i + 1);
            exit(EXIT_FAILURE);
        }
        i++;
    }
    if (pthread_create(&monitor_thread, NULL, monitor_philos, (void *)sim) != 0)
    {
        printf("Error creating monitor thread\n");
        exit(EXIT_FAILURE);
    }
    //pthread_join(monitor_thread, NULL);
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