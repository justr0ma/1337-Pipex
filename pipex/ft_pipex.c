/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:33:05 by halaqoh           #+#    #+#             */
/*   Updated: 2022/02/11 18:44:34 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(void)
{
	perror("error");
	exit(1);
}

char	*patho(char **envp, char *args)
{
	int		i;
	char	**penv;
	char	*roma;

	i = 0;
	while (!ft_strchr(envp[i]))
		i++;
	penv = ft_split(envp[i] + 5, ':');
	i = 0;
	while (penv[i])
	{
		roma = ft_strjoin(penv[i], "/");
		if (!access(ft_strjoin(roma, args), F_OK))
		{
			return (ft_strjoin(roma, args));
		}
		i++;
	}
	return (args);
}

void	pro1(int fd[2], char **argv2, char **envp)
{
	char	**args;
	int		fdo;

	fdo = open(argv2[1], O_RDONLY);
	if (fdo == -1)
		ft_exit();
	dup2(fdo, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	close(fdo);
	args = ft_split(argv2[2], ' ');
	if (execve(patho(envp, args[0]), args, NULL) == -1)
	{
		perror("command not found ");
		exit(127);
	}
}

void	pro2(int fd[2], char **argv2, char **envp)
{
	char	**args;
	int		fdo;

	fdo = open(argv2[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fdo == -1)
		ft_exit();
	dup2(fdo, 1);
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	close(fdo);
	args = ft_split(argv2[3], ' ');
	if (execve(patho(envp, args[0]), args, NULL) == -1)
	{
		perror("command not found ");
		exit(127);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1 || argc != 5)
		ft_exit();
	pid1 = fork();
	if (pid1 < 0)
		ft_exit();
	if (pid1 == 0)
		pro1(fd, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		ft_exit();
	if (pid2 == 0)
		pro2(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
