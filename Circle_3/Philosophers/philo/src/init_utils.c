/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:00:43 by hadubois          #+#    #+#             */
/*   Updated: 2025/02/15 09:25:23 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->nb_philo = ft_atoi(av[1]);
	if (ac == 6)
		data->meal_min = ft_atoi(av[5]);
	else
		data->meal_min = -1;
	data->dead_flag = 0;
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		return (cleanup_data(data), NULL);
	data->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork_mutex)
		return (cleanup_data(data), NULL);
	return (data);
}

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->fork_mutex[i], NULL) != 0)
			cleanup_mutex(data, i, STAGE_I);
		++i;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		cleanup_mutex(data, data->nb_philo, STAGE_I);
	if (pthread_mutex_init(&data->data_mutex, NULL) != 0)
		cleanup_mutex(data, data->nb_philo, STAGE_II);
}

void	init_philo_array(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].index = i;
		data->philo[i].is_alive = 1;
		data->philo[i].meal_eat = 0;
		data->philo[i].last_meal_time = data->begin_time;
		if (i % 2 != 0)
		{
			data->philo[i].r_fork = &data->fork_mutex[i];
			data->philo[i].l_fork = &data->fork_mutex[(i + 1) % data->nb_philo];
		}
		else
		{
			data->philo[i].r_fork = &data->fork_mutex[(i + 1) % data->nb_philo];
			data->philo[i].l_fork = &data->fork_mutex[i];
		}
		data->philo[i].data = data;
		if (pthread_mutex_init(&data->philo[i].philo_mutex, NULL) != 0)
			cleanup_mutex(data, i, STAGE_IV);
		++i;
	}
}

void	init_threads(t_data *data)
{
	int	i;

	i = 0;
	if (data->nb_philo == 1)
	{
		if (pthread_create(&data->philo[i].tid, NULL, alone_routine,
				&data->philo[i]) != 0)
			fail_thread_exit(data);
		return ;
	}
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i].tid, NULL, routine, &data->philo[i])
			!= 0)
			fail_thread_exit(data);
		++i;
	}
}
