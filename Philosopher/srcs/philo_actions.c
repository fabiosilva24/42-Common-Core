/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:28:13 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/20 17:58:14 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo.h"

void philo_eat(t_philosopher *philo)
{
    long long now;
    
    if (philo->simulation->num_philosophers == 1)
    {
        take_leftfork(philo);
        ft_usleep(philo->simulation->time_to_die * 2);
        pthread_mutex_lock(&philo->simulation->death_mutex);
        philo->simulation->end_simulation = 1;
        pthread_mutex_unlock(&philo->simulation->death_mutex);
        return ;
    }

    pthread_mutex_lock(&philo->simulation->death_mutex);
    if (philo->simulation->meals_required != -1 &&
            philo->meals_eaten >= philo->simulation->meals_required)
    {
        pthread_mutex_unlock(&philo->simulation->death_mutex);
        return ;
    }
    pthread_mutex_unlock(&philo->simulation->death_mutex);
    
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
        ft_usleep(50);
        take_rightfork(philo);
        if (check_end_simulation(philo->simulation))
        {
            pthread_mutex_unlock(&philo->simulation->forks[philo->right_fork]);
            return ;
        }
        take_leftfork(philo);
    }

    now = get_time_ms();
    philo->current_time = now;
    pthread_mutex_lock(&philo->simulation->death_mutex);
    philo->last_meal_time = now;
    pthread_mutex_unlock(&philo->simulation->death_mutex);

    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("%lld Philosopher %d is eating\n",
           now - philo->simulation->start_time, philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);

    ft_usleep(philo->simulation->time_to_eat);
    
    pthread_mutex_lock(&philo->simulation->death_mutex);
    philo->meals_eaten++;
    if (philo->simulation->meals_required != -1 && 
        philo->meals_eaten >= philo->simulation->meals_required)
    {
        philo->simulation->philos_full++;
        if (philo->simulation->philos_full == philo->simulation->num_philosophers)
        {
            philo->simulation->end_simulation = 1;
        }
    }
    pthread_mutex_unlock(&philo->simulation->death_mutex);

    drop_forks(philo);
    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("%lld Philosopher %d has put down the forks\n",
           now - philo->simulation->start_time, philo->id);
    printf("%lld Philosopher %d has finished eating\n",
           now - philo->simulation->start_time, philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);
}

void philo_sleep(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("%lld Philosopher %d is sleeping\n",
           get_time_ms() - philo->simulation->start_time, philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);

    ft_usleep(philo->simulation->time_to_sleep);
}

void philo_thinking(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("%lld Philosopher %d is thinking\n", get_time_ms() - philo->simulation->start_time, philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);
    //ft_usleep(50);
}