/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:27:09 by hadubois          #+#    #+#             */
/*   Updated: 2025/02/15 11:46:19 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_data
{
	int				nb_philo;
	int				meal_min;
	int				dead_flag;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			begin_time;
	pthread_t		medic;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	data_mutex;
	pthread_mutex_t	*fork_mutex;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo
{
	int				index;
	int				is_alive;
	int				meal_eat;
	size_t			last_meal_time;
	pthread_t		tid;
	pthread_mutex_t	philo_mutex;
	pthread_mutex_t	alive_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	struct s_data	*data;
}	t_philo;

typedef enum e_status
{
	EAT,
	FORK,
	SLEEP,
	THINK,
	DIE
}	t_status;

typedef enum e_stage
{
	STAGE_I,
	STAGE_II,
	STAGE_III,
	STAGE_IV,
	STAGE_V
}	t_stage;

// PARSING
int		check_nb_of_args(int ac);
int		are_nbr(char **av);
int		is_nbr(char *str);
int		are_valid_nbr(char **av);
// INIT_UTILS
t_data	*init_data(int ac, char **av);
void	init_mutex(t_data *data);
void	init_philo_array(t_data *data);
void	init_threads(t_data *data);
// ROUTINE
void	*routine(void *arg);
void	*alone_routine(void *arg);
int		philo_is_alive(t_philo *philo);
void	eat(t_philo *philo);
// PHILO_UTILS
void	print_logs(t_philo *philo, t_status state);
void	ft_usleep(size_t milliseconds, t_data *data);
size_t	get_time(t_data *data);
// SEARCH_DEAD
void	*search_dead_philo(void *arg);
int		check_die_time(t_data *data);
int		check_meal_eats(t_data *data);
void	stop_threads(t_data *data);
// CLEANUP_UTILS
void	cleanup_data(t_data *data);
void	cleanup_mutex(t_data *data, int max, t_stage stage);
void	join_all(t_data *data);
// UTILS
void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(const char *nptr);
void	fail_thread_exit(t_data *data);

#endif
