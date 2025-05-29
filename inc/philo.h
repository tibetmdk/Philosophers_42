/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:07:37 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/29 18:02:55 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//-- LIBRARIES --//
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>

//-- SOME DEFINES --
# define RED		"\033[0;31m"	// red
# define GREEN	"\033[0;32m"	//  green
# define LIGHT_BLUE	"\033[1;34m"	// light blue 
# define RST		"\033[0m"	// reset

# define INT_MAX	2147483647
# define FALSE		0
# define TRUE		1

typedef pthread_mutex_t	t_mtx;
//-- Structs --
typedef struct s_data	t_data;

typedef struct s_fork
{
	t_mtx		fork;
	int			fork_id;
}				t_fork;

typedef struct s_philo
{
	int				id;
	int				is_philo_full;
	int				meal_count;
	long			last_meal_time;
	pthread_t		thread;
	t_data			*data;
	t_fork			*left_fork;
	t_fork			*right_fork;
}				t_philo;

struct s_data
{
	int				philo_number;
	uint64_t		time_to_die;
	uint64_t		time_to_sleep;
	uint64_t		time_to_eat;
	uint64_t		start_time;
	int				limit_of_meals;
	int				simulation_finished;
	t_philo			*philos;
	t_fork			*forks;
	t_mtx			data_mutex;
	t_mtx			print_mutex;
	int				data_mtx_initialized;
	int				print_mtx_initialized;
};

// -- UTIL FUNCTIONS --
void		error_exit(char *msg, t_data *data);
uint64_t	get_time(void);
void		ft_usleep(uint64_t ms);
void		print_action(t_philo *philo, char *msg);

// -- MAIN FUNCTIONS --
void		parsing(int ac, char **av, t_data *data);
void		init(t_data *data);
void		start_threads(t_data *data);
void		*dinner(void *data);
void		*monitor(void *arg);

#endif