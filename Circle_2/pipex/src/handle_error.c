/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:33:03 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/31 11:17:59 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	handle_args_error(int ac)
{
	if (ac != 5)
	{
		errno = EINVAL;
		perror("Error");
		exit(22);
	}
}

void	check_fd_error(int fd, t_data *data)
{
	if (fd == -1)
	{
		close_and_free_all(data);
		exit(1);
	}
}

void	handle_permission_error(char *file_name)
{
	ft_putstr_fd("zsh: permission denied: ", STDERR_FILENO);
	ft_putstr_fd(file_name, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	exit_without_path(t_data *data, char **cmd_av)
{
	close_and_free_all(data);
	if (!ft_strchr(cmd_av[0], '/'))
		ft_putstr_fd("zsh: command not found: ", STDERR_FILENO);
	else
		ft_putstr_fd("zsh: no such file or directory: ", STDERR_FILENO);
	ft_putstr_fd(cmd_av[0], STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	free_split(cmd_av);
	exit(127);
}

void	handle_dup2_error(t_data *data, char **cmd_av)
{
	close_and_free_all(data);
	free_split(cmd_av);
	perror("Error: dup2()");
	exit(1);
}
