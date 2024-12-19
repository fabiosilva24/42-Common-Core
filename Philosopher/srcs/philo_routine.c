/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:46:13 by fsilva-p          #+#    #+#             */
/*   Updated: 2024/12/19 17:48:49 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


static void initialize_philovalor(t_simulation *sim, int i)
{
    sim->philosophers[i].id = i + 1;
    sim->philosophers[i].simulation = sim;
    sim->philosophers[i].left_fork = i;
    sim->philosophers[i].right_fork = (i + 1) % sim->num_philosophers;
    sim->philosophers[i].meals_eaten = 0;
    sim->philosophers[i].last_meal_time = get_time_ms();
}
void 	*philo_routine(void *arg)
{
    t_simulation *sim = (t_simulation *)arg;
    int i;

    i = 0;
	sim->philosophers = malloc(sizeof(t_philosopher) * sim->num_philosophers);
    if (!sim->philosophers)
        return (NULL);
    sim->forks = malloc(sizeof(pthread_mutex_t) * sim->num_philosophers);
    if (!sim->forks)
        return (NULL);
    pthread_mutex_init(&sim->print_mutex, NULL);
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
    return (NULL);
}


void philo_eat(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->simulation->forks[philo->left_fork]);
    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("Philosopher %d has taken the left fork\n", philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);

    pthread_mutex_lock(&philo->simulation->forks[philo->right_fork]);
    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("Philosopher %d has taken the right fork\n", philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);

    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("Philosopher %d is eating\n", philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);

    philo->last_meal_time = get_time_ms();
    usleep(philo->simulation->time_to_eat * 100);
    philo->meals_eaten++;
    
    pthread_mutex_unlock(&philo->simulation->forks[philo->right_fork]);
    pthread_mutex_unlock(&philo->simulation->forks[philo->left_fork]);
    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("Philosopher %d has put down the forks\n", philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);
}

void philo_sleep(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("Philosopher %d is sleeping\n", philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);

    usleep(philo->simulation->time_to_sleep * 100);
}

void philo_thinking(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("Philosopher %d is thinking\n", philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);

    usleep(100);
}