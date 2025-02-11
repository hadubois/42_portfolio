/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_execve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadubois <hadubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 07:53:55 by hadubois          #+#    #+#             */
/*   Updated: 2025/01/31 09:38:03 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**add_cmd_to_path(char **tab, char *cmd)
{
	int		i;
	char	*temp;

	cmd = ft_strjoin("/", cmd);
	if (!cmd)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		temp = tab[i];
		tab[i] = ft_strjoin(tab[i], cmd);
		free(temp);
		if (!tab[i])
			return (NULL);
		++i;
	}
	free(cmd);
	cmd = NULL;
	return (tab);
}

char	*check_access_to_cmd(char **tab, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	while (tab[i] && access(tab[i], F_OK) == -1)
		++i;
	if (!tab[i] && access(cmd, F_OK) == -1)
		return (NULL);
	if (tab[i])
		path = ft_strdup(tab[i]);
	else
		path = ft_strdup(cmd);
	return (path);
}

char	*find_path(char *cmd, char *envp[])
{
	int		i;
	char	**tab;
	char	*temp;
	char	*path;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
	tab = ft_split(envp[i], ':');
	temp = tab[0];
	tab[0] = strdup(tab[0] + 5);
	free(temp);
	if (!tab[0])
		return (free_split(tab), NULL);
	if (!tab)
		return (NULL);
	tab = add_cmd_to_path(tab, cmd);
	if (!tab)
		return (NULL);
	path = check_access_to_cmd(tab, cmd);
	if (!path)
		return (free_split(tab), NULL);
	return (free_split(tab), path);
}
