/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:38:45 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/25 22:38:45 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_threads(t_simulation *sim)
{
	int			i;
	pthread_t	monitor_thread;

	i = 0;
	while (i < sim->num_philosophers)
	{
		if (pthread_create(&sim->philosophers[i].thread, NULL,
				philo_routine, (void *)&sim->philosophers[i]) != 0)
		{
			printf("Error creating thread for philosopher %d\n", i + 1);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (pthread_create(&monitor_thread, NULL, monitor_philos, (void *)sim) != 0)
	{
		printf("Error creating monitor thread\n");
		exit(EXIT_FAILURE);
	}
	pthread_join(monitor_thread, NULL);
}

void	join_threads(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->num_philosophers)
	{
		if (pthread_join(sim->philosophers[i].thread, NULL) != 0)
		{
			printf("Error joining thread for philosopher %d\n", i);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
