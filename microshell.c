/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:51:00 by abaryshe          #+#    #+#             */
/*   Updated: 2025/09/23 04:55:26 by abaryshe         ###   ########.fr       */
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
	int	pip = (argv[i] && !(strcmp(argv[i], "|")));
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
	if (!pid)
	{
		argv[i] = NULL;
		if ((dup2(tmp, 0) == -1) | (close(tmp) == -1))
			exit(ft_error(ERR_FATAL));
		if (pip)
		{
			if ((dup2(fds[1], 1) == -1) | (close(fds[0]) == -1) | (close(fds[1]) == -1))
				exit(ft_error(ERR_FATAL));
		}
		execve(argv[0], argv, envp);
		exit(ft_error(ERR_EXECVE) & ft_error(*argv) & ft_error("\n"));
	}
	if (close(tmp) == -1)
		return (ft_error(ERR_FATAL));
	if (pip)
	{
		tmp = fds[0];
		if (close(fds[1]) == -1)
			return (ft_error(ERR_FATAL));
	}
	else
	{
		tmp = dup(0);
		if (tmp == -1)
			return (ft_error(ERR_FATAL));
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
	tmp = dup(0);
	if (tmp == -1)
		return (ft_error(ERR_FATAL));
	while (argv[i] && argv[++i])
	{
		argv = argv + i;
		i = 0;
		while ((argv[i]) && (strcmp(argv[i], "|")) && (strcmp(argv[i], ";")))
			i++;
		if (*argv && !strcmp(*argv, "cd"))
			ret = execute_cd(argv, i);
		else if (i)
			ret = execute_cmd(argv, i, envp);
	}
	if (close(tmp) == -1)
		return (ft_error(ERR_FATAL));
	return (ret);
}

// int	execute_cmd(char **argv, int i, char **envp, int *tmp)
// {
// 	int	pid;
// 	int	pip = (argv[i] && !(strcmp(argv[i], "|")));
// 	int	fds[2];
// 	int	ret;

// 	if (pip)
// 	{
// 		if (pipe(fds) == -1)
// 			return (ft_error(ERR_FATAL));
// 	}
// 	pid = fork();
// 	if (pid == -1)
// 		ft_error(ERR_FATAL);
// 	else if (!pid)
// 	{
// 		argv[i] = NULL;
// 		if ((dup2(*tmp, 0) == -1) | (close(*tmp) == -1))
// 			exit(ft_error(ERR_FATAL));
// 		if (pip)
// 		{
// 			if ((pip && dup2(fds[1], 1) == -1) | (close(fds[0]) ==
// -1) | (close(fds[1]) == -1))
// 				exit(ft_error(ERR_FATAL));
// 		}
// 		execve(*argv, argv, envp);
// 		exit(ft_error(ERR_EXECVE) & ft_error(*argv) & ft_error("\n"));
// 	}
// 	close(*tmp);
// 	if (pip)
// 	{
// 		*tmp = fds[0];
// 		if (close(fds[1] == -1))
// 			return (ft_error(ERR_FATAL));
// 	}
// 	else
// 	{
// 		*tmp = dup(0);
// 		if (*tmp == -1)
// 			return (ft_error(ERR_FATAL));
// 	}
// 	if (waitpid(pid, &ret, 0) == -1)
// 		return (ft_error(ERR_FATAL));
// 	if (WIFEXITED(ret))
// 		return (WEXITSTATUS(ret));
// 	return (1);
// }

/*
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
   }*/

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
