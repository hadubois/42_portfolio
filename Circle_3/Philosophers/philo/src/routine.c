/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:59:47 by hadubois          #+#    #+#             */
/*   Updated: 2025/02/15 09:14:22 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->index % 2 == 0)
	{
		print_logs(philo, THINK);
		ft_usleep(philo->data->time_to_eat, philo->data);
		if (philo->index == philo->data->nb_philo)
			ft_usleep(philo->data->time_to_eat, philo->data);
	}
	while (philo_is_alive(philo))
	{
		eat(philo);
		print_logs(philo, SLEEP);
		ft_usleep(philo->data->time_to_sleep, philo->data);
		print_logs(philo, THINK);
	}
	return (NULL);
}

void	*alone_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	print_logs(philo, FORK);
	while (philo_is_alive(philo))
	{
		ft_usleep(10, philo->data);
	}
	return (NULL);
}

int	philo_is_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_mutex);
	if (philo->is_alive == 1)
	{
		pthread_mutex_unlock(&philo->philo_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->philo_mutex);
	return (0);
}

void	eat(t_philo *philo)
{
	if (pthread_mutex_lock(philo->r_fork) == 0)
		print_logs(philo, FORK);
	if (pthread_mutex_lock(philo->l_fork) == 0)
		print_logs(philo, FORK);
	print_logs(philo, EAT);
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_lock(&philo->philo_mutex);
	philo->meal_eat++;
	philo->last_meal_time = get_time(philo->data);
	pthread_mutex_unlock(&philo->philo_mutex);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
