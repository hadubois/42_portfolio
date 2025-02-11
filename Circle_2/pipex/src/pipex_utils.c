/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 07:52:51 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/31 10:05:42 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	open_files(t_data *data, char **av)
{
	data->infile_fd = open(av[1], O_RDONLY | O_CREAT, 0644);
	if (data->infile_fd == -1)
		handle_permission_error(av[1]);
	data->outfile_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile_fd == -1)
		handle_permission_error(av[4]);
}

void	init_data(t_data *data)
{
	data->infile_fd = -1;
	data->outfile_fd = -1;
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
}

void	close_and_free_all(t_data *data)
{
	if (!data)
		return ;
	if (data->infile_fd != -1)
		close(data->infile_fd);
	if (data->outfile_fd != -1)
		close(data->outfile_fd);
	if (data->pipe_fd[0] != -1)
		close(data->pipe_fd[0]);
	if (data->pipe_fd[1] != -1)
		close(data->pipe_fd[1]);
	free(data);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}
