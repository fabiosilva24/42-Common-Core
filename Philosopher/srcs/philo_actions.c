/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:28:13 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/09 18:45:20 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo.h"

void philo_eat(t_philosopher *philo)
{
    if (philo->id % 2 == 0)
    {
        take_leftfork(philo);
        take_rightfork(philo);
    }
    else
    {
        ft_usleep(1000);
        take_leftfork(philo);
        take_rightfork(philo);
    }

    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("Philosopher %d is eating\n", philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);
    
    philo->last_meal_time = get_time_ms();
    ft_usleep((size_t)philo->simulation->time_to_eat * 1000);
    philo->meals_eaten++;
    
    drop_forks(philo);
    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("Philosopher %d has put down the forks\n", philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);
    check_if_full(philo);    
}

void philo_sleep(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("Philosopher %d is sleeping\n", philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);
    ft_usleep((size_t)philo->simulation->time_to_sleep * 1000);
}

void philo_thinking(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("Philosopher %d is thinking\n", philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);
    ft_usleep(1000);
}

void check_if_full(t_philosopher *philo)
{
    if (philo->meals_eaten >= philo->simulation->meals_required)
    {
        pthread_mutex_lock(&philo->simulation->death_mutex);
        philo->simulation->end_simulation = 1;
        pthread_mutex_unlock(&philo->simulation->death_mutex);
    }
}