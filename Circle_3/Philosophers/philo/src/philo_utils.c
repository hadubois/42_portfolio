/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:02:29 by hadubois          #+#    #+#             */
/*   Updated: 2025/02/15 11:58:24 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_logs(t_philo *philo, t_status state)
{
	size_t	current_time;
	int		dead_flag;

	pthread_mutex_lock(&philo->data->print_mutex);
	current_time = get_time(philo->data) - philo->data->begin_time;
	pthread_mutex_lock(&philo->data->data_mutex);
	dead_flag = philo->data->dead_flag;
	pthread_mutex_unlock(&philo->data->data_mutex);
	if (!dead_flag)
	{
		if (state == FORK)
			printf("%ld %d has taken a fork\n", current_time, philo->index
				+ 1);
		if (state == EAT)
			printf("%ld %d is eating\n", current_time, philo->index + 1);
		if (state == SLEEP)
			printf("%ld %d is sleeping\n", current_time, philo->index + 1);
		if (state == THINK)
			printf("%ld %d is thinking\n", current_time, philo->index + 1);
	}
	if (state == DIE)
		printf("%ld %d died\n", current_time, philo->index + 1);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	ft_usleep(size_t milliseconds, t_data *data)
{
	size_t	current;

	current = get_time(data);
	while ((get_time(data) - current) < milliseconds)
		usleep(10);
}

size_t	get_time(t_data *data)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		ft_putstr_fd("Error: gettimeofday()\n", 2);
		cleanup_mutex(data, data->nb_philo, STAGE_V);
		exit(1);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	fail_thread_exit(t_data *data)
{
	cleanup_mutex(data, data->nb_philo, STAGE_V);
	ft_putstr_fd("Error: init_threads(): medic\n", 2);
	exit(1);
}
