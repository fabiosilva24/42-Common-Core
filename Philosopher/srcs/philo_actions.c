/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:37:46 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/25 22:37:46 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	take_forks(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		take_leftfork(philo);
		take_rightfork(philo);
	}
	else
	{
		ft_usleep(50);
		take_rightfork(philo);
		take_leftfork(philo);
	}
	return (0);
}

static void	handle_eating(t_philosopher *philo)
{
	update_meal_time(philo);
	ft_usleep(philo->simulation->time_to_eat);
	if (!check_end_simulation(philo->simulation))
	{
		finish_eating(philo);
		drop_forks(philo);
		print_eating_status(philo);
	}
	else
		drop_forks(philo);
}

void	philo_eat(t_philosopher *philo)
{
	if (check_end_simulation(philo->simulation))
		return ;
	if (handle_single_philo(philo))
		return ;
	if (check_meals_limit(philo))
		return ;
	take_forks(philo);
	handle_eating(philo);
}

void	philo_sleep(t_philosopher *philo)
{
	if (!check_end_simulation(philo->simulation))
	{
		pthread_mutex_lock(&philo->simulation->print_mutex);
		printf("%lld Philosopher %d is sleeping\n",
			get_time_ms() - philo->simulation->start_time, philo->id);
		pthread_mutex_unlock(&philo->simulation->print_mutex);
		ft_usleep(philo->simulation->time_to_sleep);
	}
}

void	philo_thinking(t_philosopher *philo)
{
	if (!check_end_simulation(philo->simulation))
	{
		pthread_mutex_lock(&philo->simulation->print_mutex);
		printf("%lld Philosopher %d is thinking\n",
			get_time_ms() - philo->simulation->start_time, philo->id);
		pthread_mutex_unlock(&philo->simulation->print_mutex);
	}
}
