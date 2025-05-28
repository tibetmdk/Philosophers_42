/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:32:28 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/28 15:54:27 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	start_threads(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	data->start_time = get_time();
	i = -1;
	while (++i < data->philo_number)
	{
		data->philos[i].last_meal_time = data->start_time;
		if (pthread_create(&data->philos[i].thread, NULL, \
		dinner, &data->philos[i]) != 0)
			error_exit("An error occured while creating thread!", data);
	}
	if (pthread_create(&monitor_thread, NULL, monitor, data) != 0)
		error_exit("Failed to create monitor thread", data);
	i = -1;
	while (++i < data->philo_number)
		pthread_join(data->philos[i].thread, NULL);
	pthread_join(monitor_thread, NULL);
}
