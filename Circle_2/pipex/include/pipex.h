/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 07:58:08 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/31 11:18:11 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include "../lib/libft/include/libft.h"

typedef struct s_data
{
	int		infile_fd;
	int		outfile_fd;
	int		pipe_fd[2];

}	t_data;

//handle_error
void	handle_args_error(int ac);
void	check_fd_error(int fd, t_data *data);
void	handle_permission_error(char *file_name);
void	exit_without_path(t_data *data, char **cmd_av);
void	handle_dup2_error(t_data *data, char **cmd_av);
//handle_execve
char	**add_cmd_to_path(char **tab, char *cmd);
char	*check_access_to_cmd(char **tab, char *cmd);
char	*find_path(char *cmd, char *envp[]);
//pipex_utils
void	open_files(t_data *data, char **av);
void	init_data(t_data *data);
void	close_and_free_all(t_data *data);
void	free_split(char **split);
#endif
