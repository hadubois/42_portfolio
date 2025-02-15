/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_dead.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 08:30:53 by hadubois          #+#    #+#             */
/*   Updated: 2025/02/15 11:57:52 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*search_dead_philo(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (!check_die_time(data) || check_meal_eats(data))
		{
			pthread_mutex_lock(&data->data_mutex);
			data->dead_flag = 1;
			pthread_mutex_unlock(&data->data_mutex);
			return (stop_threads(data), NULL);
		}
		ft_usleep(10, data);
	}
	return (NULL);
}

int	check_die_time(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->philo[i].philo_mutex);
		if (get_time(data) - data->philo[i].last_meal_time > data->time_to_die)
		{
			pthread_mutex_unlock(&data->philo[i].philo_mutex);
			return (print_logs(&data->philo[i], DIE), 0);
		}
		pthread_mutex_unlock(&data->philo[i].philo_mutex);
		++i;
	}
	return (1);
}

int	check_meal_eats(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (data->meal_min == -1)
		return (0);
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->philo[i].philo_mutex);
		if (data->philo[i].meal_eat >= data->meal_min)
			count++;
		pthread_mutex_unlock(&data->philo[i].philo_mutex);
		++i;
	}
	if (count == data->nb_philo)
		return (1);
	return (0);
}

void	stop_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->philo[i].philo_mutex);
		data->philo[i].is_alive = 0;
		pthread_mutex_unlock(&data->philo[i].philo_mutex);
		++i;
	}
}
