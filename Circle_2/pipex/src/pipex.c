/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:18:06 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/31 11:18:39 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	handle_child1(t_data *data, char **av, char **envp)
{
	char	*path;
	char	**cmd_av;

	check_fd_error(data->infile_fd, data);
	cmd_av = ft_split(av[2], ' ');
	if (!cmd_av || !cmd_av[0])
	{
		close_and_free_all(data);
		free_split(cmd_av);
		errno = ENOENT;
		perror("Error: ft_split()");
		exit(1);
	}
	path = find_path(cmd_av[0], envp);
	if (!path)
		exit_without_path(data, cmd_av);
	if (dup2(data->infile_fd, STDIN_FILENO) == -1)
		handle_dup2_error(data, cmd_av);
	if (dup2(data->pipe_fd[1], STDOUT_FILENO) == -1)
		handle_dup2_error(data, cmd_av);
	close_and_free_all(data);
	execve(path, cmd_av, envp);
	free_split(cmd_av);
	exit(1);
}

void	handle_child2(t_data *data, char **av, char **envp)
{
	char	*path;
	char	**cmd_av;

	check_fd_error(data->outfile_fd, data);
	cmd_av = ft_split(av[3], ' ');
	if (!cmd_av || !av[3][0])
	{
		close_and_free_all(data);
		free_split(cmd_av);
		errno = ENOENT;
		perror("Error: split() fail");
		exit(1);
	}
	path = find_path(cmd_av[0], envp);
	if (!path)
		exit_without_path(data, cmd_av);
	if (dup2(data->pipe_fd[0], STDIN_FILENO) == -1)
		handle_dup2_error(data, cmd_av);
	if (dup2(data->outfile_fd, STDOUT_FILENO) == -1)
		handle_dup2_error(data, cmd_av);
	close_and_free_all(data);
	execve(path, cmd_av, envp);
	free_split(cmd_av);
	exit(1);
}

int	main(int ac, char *av[], char *envp[])
{
	t_data	*data;
	pid_t	pid1;
	pid_t	pid2;

	handle_args_error(ac);
	data = malloc(sizeof(t_data));
	if (!data)
		return (perror("Error"), EXIT_FAILURE);
	init_data(data);
	open_files(data, av);
	if (pipe(data->pipe_fd) == -1)
		return (perror("Error: impossible to create pipe"), EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("fork()"), EXIT_FAILURE);
	if (pid1 == 0)
		handle_child1(data, av, envp);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("fork()"), EXIT_FAILURE);
	if (pid2 == 0)
		handle_child2(data, av, envp);
	close_and_free_all(data);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
