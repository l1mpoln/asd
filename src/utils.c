/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:34:56 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/01/30 13:19:18 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	find_all_paths(char **envp, t_cmd *cmd)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	cmd->path = *envp + 6;
	cmd->cmd_paths = ft_split(cmd->path, ':');
}

void	open_files(t_cmd *cmd, char *first_path, char *second_path)
{
	cmd->fd_in = open (first_path, O_RDONLY);
	if (cmd->fd_in < 0)
		ft_error("Error.");
	cmd->fd_out = open (second_path, O_WRONLY | O_TRUNC | O_CREAT, 777);
	if (cmd->fd_out < 0)
		ft_error("Error.");
}

void	ft_error(char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}
