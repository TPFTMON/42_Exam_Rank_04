/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:51:00 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/17 11:46:15 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

int	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (1);
}

int	execute_cmd(char **argv, char **envp)
{
	int	pid;
	int	ret;

	pid = fork();
	if (pid == -1)
		ft_error(ERR_FATAL);
	else if (!pid)
	{
		execve(argv[0], argv, envp);
		return (ft_error(ERR_EXECVE) & ft_error(argv[0]) & ft_error("\n"));
	}
	if (waitpid(pid, &ret, 0) == -1)
		return (ft_error(ERR_FATAL));
	if (WIFEXITED(ret))
		return (WEXITSTATUS(ret));
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int	ret = 0;

	if (argc < 2)
		return (0);
	ret = execute_cmd(argv + 1, envp);
	return (ret);
}
