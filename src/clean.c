/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:32:59 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/30 15:09:16 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	clean_all(t_data *data)
{
	int     i;

	i = -1;
	if (data->forks)
	{
		while (++i < data->philo_number)
			free(data->philos[i]);
	}
}