/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:51:00 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/18 16:37:57 by abaryshe         ###   ########.fr       */
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

int	execute_cd(char **argv, int i)
{
	if (i != 2)
		return (ft_error(ERR_CD_ARG));
	if (argv[1] && chdir(argv[1]) == -1)
		return (ft_error(ERR_CD_FAIL) & ft_error(argv[1]) & ft_error("\n"));
	return (0);
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
	int	i = 0;

	if (argc < 2)
		return (0);
	while (argv[i] && argv[++i])
	{
		argv = argv + i;
		i = 0;
		while ((argv[i]) && (strcmp(argv[i], ";")))
			i++;
		if (*argv && (strcmp(*argv, "cd") == 0))
			ret = execute_cd(argv, i);
		else if (i)
			ret = execute_cmd(argv, i, envp);
	}
	return (ret);
}

/*
int     main(int argc, char **argv)
{
	int	ret;

	ret = 0;
	argv = argv + 1;
	if (argc != 1)
		ret = execute_cd(argv, 2);
	return (ret);
}*/

/*
int     main(void)
{
	int	ret;

	ret = chdir("miaouWAF");
	return (ret);
}*/
