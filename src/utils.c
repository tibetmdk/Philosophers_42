/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:34:26 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/28 19:55:03 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((uint64_t)tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

void	ft_usleep(uint64_t ms)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(100);
}

void	error_exit(char *msg, t_data *data)
{
	(void)data;
	printf(RED"%s"RST, msg);
	exit(EXIT_FAILURE);
}

void	print_action(t_philo *philo, char *msg)
{
	long	timestamp;

	pthread_mutex_lock(&philo->data->data_mutex);
	if (philo->data->simulation_finished)
	{
		pthread_mutex_unlock(&philo->data->data_mutex);
		return ;
	}
	timestamp = get_time() - philo->data->start_time;
	pthread_mutex_unlock(&philo->data->data_mutex);
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%s%ld %s%d %s%s\n", GREEN, timestamp, \
	LIGHT_BLUE, philo->id, RST, msg);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
