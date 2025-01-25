/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:38:14 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/25 22:38:14 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	check_philo_death(t_simulation *sim, int i)
{
	long long	now;

	now = get_time_ms();
	if (now - sim->philosophers[i].last_meal_time > sim->time_to_die)
	{
		pthread_mutex_lock(&sim->print_mutex);
		printf("%lld Philosopher %d died\n",
			get_time_ms() - sim->start_time, sim->philosophers[i].id);
		pthread_mutex_unlock(&sim->print_mutex);
		pthread_mutex_lock(&sim->death_mutex);
		sim->end_simulation = 1;
		pthread_mutex_unlock(&sim->death_mutex);
		return (1);
	}
	return (0);
}

static int	monitor_loop(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->num_philosophers)
	{
		if (check_philo_death(sim, i))
			return (1);
		i++;
	}
	if (check_end_simulation(sim))
		return (1);
	ft_usleep(150);
	return (0);
}

void	*monitor_philos(void *arg)
{
	t_simulation	*sim;

	sim = (t_simulation *)arg;
	while (!check_end_simulation(sim))
	{
		if (monitor_loop(sim))
			return (NULL);
	}
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (!check_end_simulation(philo->simulation))
	{
		philo_eat(philo);
		if (check_end_simulation(philo->simulation))
			break ;
		philo_sleep(philo);
		if (check_end_simulation(philo->simulation))
			break ;
		philo_thinking(philo);
		if (check_end_simulation(philo->simulation))
			break ;
	}
	return (NULL);
}
