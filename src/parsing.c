/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:05:05 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/28 16:45:02 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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

static long	ft_atol(char *str, t_data *data)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
		error_exit("An error occurred in tf_atol", data);
	if (str[i] == '+')
		i++;
	if (!is_digit(str[i]))
		error_exit("An error occurred in tf_atol", data);
	while (!is_space(str[i]) && str[i] != '\0')
	{
		if (!is_digit(str[i]))
			error_exit("An error occurred in tf_atol", data);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (result > INT_MAX)
		error_exit("An error occurred in tf_atol", data);
	return (result);
}

void	parsing(int ac, char **av, t_data *data)
{
	data->philo_number = ft_atol(av[1], data);
	data->time_to_die = ft_atol(av[2], data);
	if (data->time_to_die < 60)
		error_exit("You can't give a time smaller than 60 ms", data);
	data->time_to_eat = ft_atol(av[3], data);
	if (data->time_to_eat < 60)
		error_exit("You can't give a time smaller than 60 ms", data);
	data->time_to_sleep = ft_atol(av[4], data);
	if (data->time_to_sleep < 60)
		error_exit("You can't give a time smaller than 60 ms", data);
	if (ac == 6)
		data->limit_of_meals = ft_atol(av[5], data);
}
