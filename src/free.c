/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:58:46 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/01/30 13:21:25 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	struct_free(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->cmd_args[i])
	{
		free(cmd->cmd_args[i]);
		i++;
	}
	free(cmd->cmd_args);
	free(cmd->command);
}

void	free_parent(t_cmd *cmd)
{
	int	i;

	i = 0;
	close(cmd->fd_in);
	close(cmd->fd_out);
	while (cmd->cmd_paths[i])
	{
		free(cmd->cmd_paths[i]);
		i++;
	}
	free(cmd->cmd_paths);
}
