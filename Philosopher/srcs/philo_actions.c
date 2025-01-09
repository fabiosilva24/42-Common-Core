/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:28:13 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/09 20:56:22 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo.h"

void philo_eat(t_philosopher *philo)
{
    if (philo->simulation->num_philosophers == 1)
    {
        take_leftfork(philo);
        ft_usleep(philo->simulation->time_to_die * 1000);
        return ;
    }
    if (philo->id % 2 == 0)
    {
        take_leftfork(philo);
        if (check_end_simulation(philo->simulation))
        {
            pthread_mutex_unlock(&philo->simulation->forks[philo->left_fork]);
            return ;
        }
        take_rightfork(philo);
    }
    else
    {
        ft_usleep(1000);
        take_rightfork(philo);
        if (check_end_simulation(philo->simulation))
        {
            pthread_mutex_unlock(&philo->simulation->forks[philo->right_fork]);
            return ;
        }
        take_leftfork(philo);
    }

    philo->last_meal_time = get_time_ms();

    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("Philosopher %d is eating\n", philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);
    
    ft_usleep((size_t)philo->simulation->time_to_eat * 1000);
    philo->meals_eaten++;
    
    drop_forks(philo);
    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("Philosopher %d has put down the forks\n", philo->id);
    printf("Philosopher %d has finished eating\n", philo->id);
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