/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:04:15 by hadubois          #+#    #+#             */
/*   Updated: 2025/02/15 09:24:22 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char *av[])
{
	t_data	*data;

	if (!check_nb_of_args(ac) || !are_nbr(av) || !are_valid_nbr(av))
		return (EXIT_FAILURE);
	data = init_data(ac, av);
	if (!data)
		return (ft_putstr_fd("Error: init_data()\n", 2), EXIT_FAILURE);
	init_mutex(data);
	data->begin_time = get_time(data);
	init_philo_array(data);
	init_threads(data);
	if (pthread_create(&data->medic, NULL, search_dead_philo, data) != 0)
		fail_thread_exit(data);
	join_all(data);
	cleanup_mutex(data, data->nb_philo, STAGE_V);
	return (EXIT_SUCCESS);
}
