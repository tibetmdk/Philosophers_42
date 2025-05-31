/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:03:33 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/31 03:25:27 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	check_death(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->data_mutex);
	while (i < data->philo_number)
	{
		if (get_time() - data->philos[i].last_meal_time > data->time_to_die)
		{
			data->simulation_finished = 1;
			pthread_mutex_unlock(&data->data_mutex);
			pthread_mutex_lock(&data->print_mutex);
			printf("%s%lu %d died\n%s", RED, get_time() - data->start_time, \
			data->philos[i].id, RST);
			pthread_mutex_unlock(&data->print_mutex);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&data->data_mutex);
	return (0);
}

static int	check_full(t_data *data)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (data->limit_of_meals == 0)
		return (0);
	pthread_mutex_lock(&data->data_mutex);
	while (++i < data->philo_number)
		if (data->philos[i].meal_count >= data->limit_of_meals)
			count++;
	if (count == data->philo_number)
		data->simulation_finished = 1;
	pthread_mutex_unlock(&data->data_mutex);
	return (count == data->philo_number);
}

void	*monitor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!check_death(data) && !check_full(data))
		ft_usleep(200);
	return (NULL);
}
