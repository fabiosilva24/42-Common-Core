/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:28:13 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/16 20:08:43 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo.h"

void philo_eat(t_philosopher *philo)
{
    
    if (philo->simulation->num_philosophers == 1)
    {
        take_leftfork(philo);
        ft_usleep(philo->simulation->time_to_die * 1000);
        pthread_mutex_lock(&philo->simulation->death_mutex);
        philo->simulation->end_simulation = 1;
        pthread_mutex_unlock(&philo->simulation->death_mutex);
        return ;
    }
    
    if (philo->id % 2 == 0)
    {
        //ft_usleep(1000);
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
        take_rightfork(philo);
        if (check_end_simulation(philo->simulation))
        {
            pthread_mutex_unlock(&philo->simulation->forks[philo->right_fork]);
            return ;
        }
        take_leftfork(philo);
    }

    philo->current_time = get_time_ms();
pthread_mutex_lock(&philo->simulation->death_mutex);
philo->last_meal_time = get_time_ms(); // Use fresh timestamp
pthread_mutex_unlock(&philo->simulation->death_mutex);

pthread_mutex_lock(&philo->simulation->print_mutex);
printf("%lld Philosopher %d is eating\n",
       get_time_ms() - philo->simulation->start_time, philo->id);
pthread_mutex_unlock(&philo->simulation->print_mutex);

// If ft_usleep already uses ms, remove "* 1000":
ft_usleep(philo->simulation->time_to_eat);
philo->meals_eaten++;

drop_forks(philo);
pthread_mutex_lock(&philo->simulation->print_mutex);
printf("%lld Philosopher %d has put down the forks\n",
       get_time_ms() - philo->simulation->start_time, philo->id);
printf("%lld Philosopher %d has finished eating\n",
       get_time_ms() - philo->simulation->start_time, philo->id);
pthread_mutex_unlock(&philo->simulation->print_mutex);
    check_if_full(philo);    
}

void philo_sleep(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("%lld Philosopher %d is sleeping\n",
           get_time_ms() - philo->simulation->start_time, philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);

    // If ft_usleep uses ms, remove "* 1000"
    ft_usleep(philo->simulation->time_to_sleep);
}

void philo_thinking(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->simulation->print_mutex);
    printf("%lld Philosopher %d is thinking\n", get_time_ms() - philo->simulation->start_time, philo->id);
    pthread_mutex_unlock(&philo->simulation->print_mutex);
    //ft_usleep(50);
}

void check_if_full(t_philosopher *philo)
{
    if (philo->simulation->meals_required != -1 && philo->meals_eaten >= philo->simulation->meals_required)
    {
        pthread_mutex_lock(&philo->simulation->death_mutex);
        philo->simulation->philos_full++;
        if (philo->simulation->philos_full == philo->simulation->num_philosophers)
        {
            philo->simulation->end_simulation = 1;
        }
        pthread_mutex_unlock(&philo->simulation->death_mutex);
    }
}