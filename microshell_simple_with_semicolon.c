/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:51:00 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/17 13:25:51 by abaryshe         ###   ########.fr       */
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

int	execute_cmd(char **argv, int i, char **envp)
{
	int	pid;
	int	ret;

	if (strcmp(*argv, ";") == 0)
		return (0);
	pid = fork();
	if (pid == -1)
		ft_error(ERR_FATAL);
	else if (!pid)
	{
		argv[i] = NULL;
		execve(*argv, argv, envp);
		return (ft_error(ERR_EXECVE) & ft_error(*argv) & ft_error("\n"));
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
	int	i = 1;

	if (argc < 2)
		return (0);
	while (argv[i])
	{
		argv = argv + i;
		while ((argv[i]) && (strcmp(argv[i], ";")))
		      i++;
		ret = execute_cmd(argv, i, envp);
	}
	return (ret);
}
