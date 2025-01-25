/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:37:59 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/25 22:37:59 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	handle_single_philo(t_philosopher *philo)
{
	if (philo->simulation->num_philosophers == 1)
	{
		take_leftfork(philo);
		ft_usleep(philo->simulation->time_to_die * 2);
		pthread_mutex_lock(&philo->simulation->death_mutex);
		philo->simulation->end_simulation = 1;
		pthread_mutex_unlock(&philo->simulation->death_mutex);
		return (1);
	}
	return (0);
}

int	check_meals_limit(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->simulation->death_mutex);
	if (philo->simulation->meals_required != -1
		&& philo->meals_eaten >= philo->simulation->meals_required)
	{
		pthread_mutex_unlock(&philo->simulation->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->simulation->death_mutex);
	return (0);
}

void	update_meal_time(t_philosopher *philo)
{
	long long	now;

	now = get_time_ms();
	pthread_mutex_lock(&philo->simulation->death_mutex);
	philo->last_meal_time = now;
	pthread_mutex_unlock(&philo->simulation->death_mutex);
	if (!check_end_simulation(philo->simulation))
	{
		pthread_mutex_lock(&philo->simulation->print_mutex);
		printf("%lld Philosopher %d is eating\n",
			now - philo->simulation->start_time, philo->id);
		pthread_mutex_unlock(&philo->simulation->print_mutex);
	}
}

void	finish_eating(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->simulation->death_mutex);
	philo->meals_eaten++;
	if (philo->simulation->meals_required != -1
		&& philo->meals_eaten >= philo->simulation->meals_required)
	{
		philo->simulation->philos_full++;
		if (philo->simulation->philos_full
			== philo->simulation->num_philosophers)
			philo->simulation->end_simulation = 1;
	}
	pthread_mutex_unlock(&philo->simulation->death_mutex);
}

void	print_eating_status(t_philosopher *philo)
{
	if (!check_end_simulation(philo->simulation))
	{
		pthread_mutex_lock(&philo->simulation->print_mutex);
		printf("%lld Philosopher %d has put down the forks\n",
			get_time_ms() - philo->simulation->start_time, philo->id);
		printf("%lld Philosopher %d has finished eating\n",
			get_time_ms() - philo->simulation->start_time, philo->id);
		pthread_mutex_unlock(&philo->simulation->print_mutex);
	}
}
