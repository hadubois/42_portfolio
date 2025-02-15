/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:28:31 by hadubois          #+#    #+#             */
/*   Updated: 2025/02/15 11:41:41 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_data(t_data *data)
{
	free(data->fork_mutex);
	free(data->philo);
	free(data);
}

void	handle_stage1(t_data *data, int max, t_stage stage)
{
	int	i;

	i = 0;
	if (stage > STAGE_I)
		max = data->nb_philo;
	while (i < max)
	{
		pthread_mutex_destroy(&data->fork_mutex[i]);
		i++;
	}
}

void	handle_stage4(t_data *data, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		pthread_mutex_destroy(&data->philo[i].philo_mutex);
		i++;
	}
}

void	cleanup_mutex(t_data *data, int max, t_stage stage)
{
	if (stage >= STAGE_I)
		handle_stage1(data, max, stage);
	if (stage >= STAGE_II)
		pthread_mutex_destroy(&data->data_mutex);
	if (stage >= STAGE_III)
		pthread_mutex_destroy(&data->print_mutex);
	if (stage >= STAGE_IV)
		handle_stage4(data, max);
	cleanup_data(data);
	if (stage < STAGE_V)
	{
		ft_putstr_fd("Error: pthread_mutex_init()\n", 2);
		exit(1);
	}
}

void	join_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philo[i].tid, NULL);
		i++;
	}
	pthread_join(data->medic, NULL);
}
