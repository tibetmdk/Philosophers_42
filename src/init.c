/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:44:36 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/28 16:14:21 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	init_philos(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->philo_number)
	{
		data->philos[i].id = i + 1;
		data->philos[i].is_philo_full = FALSE;
		data->philos[i].meal_count = 0;
		data->philos[i].data = data;
		data->philos[i].right_fork = &data->forks[(i + 1) % data->philo_number];
		data->philos[i].left_fork = &data->forks[i];
		i++;
	}
}

void	init(t_data *data)
{
	int		i;

	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_number);
	if (!data->philos)
		error_exit("Problem in malloc!", data);
	data->simulation_finished = 0;
	data->forks = (t_fork *)malloc(sizeof(t_fork) * data->philo_number);
	if (!data->forks)
		error_exit("Problem in malloc!", data);
	if (pthread_mutex_init(&data->data_mutex, NULL) == 0)
		data->data_mtx_initialized = 1;
	if (pthread_mutex_init(&data->print_mutex, NULL) == 0)
		data->print_mtx_initialized = 1;
	i = -1;
	while (++i < data->philo_number)
	{
		if (pthread_mutex_init(&data->forks[i].fork, NULL) != 0)
			error_exit("Fork mutex init failed!", data);
		data->forks[i].fork_id = i;
	}
	init_philos(data);
}
