/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-p <fsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:38:20 by fsilva-p          #+#    #+#             */
/*   Updated: 2025/01/25 22:38:20 by fsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

long long	get_time_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		write(2, "gettimeofday() error\n", 21);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

long long	get_elapsed_time(t_simulation *sim)
{
	return (get_time_ms() - sim->start_time);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time_ms();
	while ((get_time_ms() - start) < milliseconds)
		usleep(500);
	return (0);
}
