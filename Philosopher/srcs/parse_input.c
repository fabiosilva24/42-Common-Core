/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:37:35 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/25 22:37:35 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	parse_input(t_simulation *sim, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Usage: ./philo num_philosophers time_to_die time_to_eat");
		printf(" time_to_sleep [max_meals]\n");
		return (1);
	}
	sim->num_philosophers = ft_atoi(argv[1]);
	sim->time_to_die = ft_atoi(argv[2]);
	sim->time_to_eat = ft_atoi(argv[3]);
	sim->time_to_sleep = ft_atoi(argv[4]);
	if (sim->num_philosophers <= 0 || sim->num_philosophers > 250
		|| sim->time_to_die <= 0 || sim->time_to_eat <= 0
		|| sim->time_to_sleep <= 0)
	{
		printf("Invalid Input parameters\n");
		return (1);
	}
	if (argv[5])
	{
		check_meal_required(sim, argc, argv);
	}
	else
		sim->meals_required = -1;
	return (0);
}
