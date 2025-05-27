/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:05:05 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/27 15:19:01 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static long	ft_atol(char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	if (!is_digit(str[i]))
		return (-1);
	while (!is_space(str[i]) && str[i] != '\0')
	{
		if (!is_digit(str[i]))
			return (-1);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (result > INT_MAX)
		return (-1);
	else
		return (result);
}

void	parsing(int ac, char **av, t_data *data)
{
	data->philo_number = ft_atol(av[1]);
	if (data->philo_number == -1)
		error_exit("Wrong input", data);
	data->time_to_die = ft_atol(av[2]);
	if (data->time_to_die == -1 || data->time_to_die < 60)
		error_exit("Wrong input", data);
	data->time_to_eat = ft_atol(av[3]);
	if (data->time_to_eat == -1 || data->time_to_die < 60)
		error_exit("Wrong input", data);
	data->time_to_sleep = ft_atol(av[4]);
	if (data->time_to_sleep == -1 || data->time_to_die < 60)
		error_exit("Wrong input", data);
	if (ac = 6)
	{
		data->limit_of_meals = ft_atol(ft_atol(av[5]));
		if (data->limit_of_meals == -1)
			error_exit("Wrong input", data);
	}	
}


