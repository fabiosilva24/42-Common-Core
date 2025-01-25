/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_simulation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:46:13 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/20 17:54:49 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_end_simulation(t_simulation *sim)
{
	int	end_simulation;

	pthread_mutex_lock(&sim->death_mutex);
	end_simulation = sim->end_simulation;
	pthread_mutex_unlock(&sim->death_mutex);
	return (end_simulation);
}
