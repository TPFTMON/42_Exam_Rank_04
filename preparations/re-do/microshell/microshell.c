/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 04:08:08 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/27 05:55:08 by abaryshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	tmp;

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
	return(1);
}

int	exec_cd(char **av, int i)
{
	if (i != 2)
		return (ft_error(ERR_CD_ARG));
	if (av[1] && chdir(av[1]) == -1)
		return (ft_error(ERR_CD_FAIL) & ft_error(av[1]) & ft_error("\n"));
	return (0);
}

int	exec_cmd(char **av, int i, char **envp)
{
	int	pid;
	int	pip = (av[i] && !strcmp(av[i], "|"));
	int	fds[2];
	int	ret;

	if (pip)
	{
		if (pipe(fds) == -1)
			return (ft_error(ERR_FATAL));
	}
	pid = fork();
	if (pid == -1)
		return (ft_error(ERR_FATAL));
	if (pid == 0)
	{
		av[i] = NULL;
		if ((dup2(tmp, 0) == -1) | (close(tmp) == -1))
			exit(ft_error(ERR_FATAL));
		if (pip)
		{
			if ((dup2(fds[1], 1) == -1) | (close(fds[0]) == -1) | (close(fds[1]) == -1))
				exit(ft_error(ERR_FATAL));
		}
		execve(av[0], av, envp);
		exit(ft_error(ERR_EXECVE) & ft_error(av[0]) & ft_error("\n"));
	}
	if (close(tmp) == -1)
		ft_error(ERR_FATAL);
	if (pip)
	{
		tmp = fds[0];
		if (close(fds[1]) == -1)
			ft_error(ERR_FATAL);
	}
	else
	{
		tmp = dup(0);
		if (tmp == -1)
			ft_error(ERR_FATAL);
	}
	if (waitpid(pid, &ret, 0) == -1)
		return (ft_error(ERR_FATAL));
	if (WIFEXITED(ret))
		return (WEXITSTATUS(ret));
	return (1);
}

int main(int ac, char **av, char **envp)
{
	int	i = 0;
	int	ret = 0;

	if (ac < 2)
		return (0);
	tmp = dup(0);
	if (tmp == -1)
		return(ft_error(ERR_FATAL));
	while(av[i] && av[++i])
	{
		av = av + i;
		i = 0;
		while (av[i] && (strcmp(av[i], "|")) && (strcmp(av[i], ";")))
			i++;
		if ((*av) && !strcmp(*av, "cd"))
			ret = exec_cd(av, i);
		else if (i)
			ret = exec_cmd(av, i, envp);
	}
	if (close(tmp) == -1)
		return (ft_error(ERR_FATAL));
	return (ret);
}
