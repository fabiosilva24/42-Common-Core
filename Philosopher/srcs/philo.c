/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:46:19 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/09 21:10:25 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
	t_simulation sim;
	
	if (parse_input(&sim ,argc, argv) != 0)
		return (1);
	if (init_simulation(&sim) != 0)
		return (1);

	create_threads(&sim);
	join_threads(&sim);

	cleanup_simulation(&sim);
	return (0);
}

