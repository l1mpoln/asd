/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:31:49 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/01/30 13:49:15 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../includes/libft/libft.h" // my libft
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

//strcut that contain our variables
typedef struct s_cmd
{
	char	*path;
	char	**cmd_paths;
	char	**cmd_args;
	char	*command;
	pid_t	pid1;
	pid_t	pid2;
	int		fd_in;
	int		fd_out;
	int		tube[2];
}	t_cmd;

//commands
void		first_command(t_cmd *cmd, char **av, char **envp);
void		second_command(t_cmd *cmd, char **av, char **envp);

//utils
void		ft_error(char *error);
void		open_files(t_cmd *cmd, char *first_path, char *second_path);
void		find_all_paths(char **envp, t_cmd *cmd);

//free
void		struct_free(t_cmd *cmd);
void		free_parent(t_cmd *cmd);

#endif
