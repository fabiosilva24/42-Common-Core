/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:08:37 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/25 22:08:37 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_meal_required(t_simulation *sim, int argc, char **argv)
{
	(void)argc;
	sim->meals_required = ft_atoi(argv[5]);
	if (sim->meals_required <= 0)
	{
		printf("Invalid Input parameters\n");
		return (1);
	}
	return (0);
}
