/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:45:35 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/02/01 17:06:56 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	child_error(char *error)
{
	write(2, "Unavaible command", ft_strlen(error));
	return (1);
}

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	first_command(t_cmd *cmd, char **av, char **envp)
{
	dup2(cmd->tube[1], 1);
	close(cmd->tube[0]);
	dup2(cmd->fd_in, 0);
	cmd->cmd_args = ft_split(av[2], ' ');
	cmd->command = get_cmd(cmd->cmd_paths, cmd->cmd_args[0]);
	if (!cmd->command)
	{
		struct_free(cmd);
		child_error("Unavaible command");
		exit(1);
	}
	execve(cmd->command, cmd->cmd_args, envp);
}

void	second_command(t_cmd *cmd, char **av, char **envp)
{
	dup2(cmd->tube[0], 0);
	close(cmd->tube[1]);
	dup2(cmd->fd_out, 1);
	cmd->cmd_args = ft_split(av[3], ' ');
	cmd->command = get_cmd(cmd->cmd_paths, cmd->cmd_args[0]);
	if (!cmd->command)
	{
		struct_free(cmd);
		child_error("Unavaible command");
		exit(1);
	}
	execve(cmd->command, cmd->cmd_args, envp);
}
