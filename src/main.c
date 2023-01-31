/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:32:42 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/01/30 13:23:21 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_pipes(t_cmd *cmd)
{
	close(cmd->tube[0]);
	close(cmd->tube[1]);
}

int	main(int ac, char **av, char **envp)
{
	t_cmd	cmd;

	if (ac != 5)
		ft_error("Error.");
	find_all_paths(envp, &cmd);
	open_files(&cmd, av[1], av[4]);
	if (pipe(cmd.tube) < 0)
		ft_error("Error with pipe.");
	cmd.pid1 = fork();
	if (cmd.pid1 < 0)
		ft_error("Error with fork");
	if (cmd.pid1 == 0)
		first_command(&cmd, av, envp);
	cmd.pid2 = fork();
	if (cmd.pid2 < 0)
		ft_error("Error with fork 2.");
	if (cmd.pid2 == 0)
		second_command(&cmd, av, envp);
	close_pipes(&cmd);
	waitpid(cmd.pid1, NULL, 0);
	waitpid(cmd.pid2, NULL, 0);
	free_parent(&cmd);
	return (0);
}
