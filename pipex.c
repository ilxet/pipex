/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:08:41 by aadamik           #+#    #+#             */
/*   Updated: 2024/06/27 16:46:18 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	ft_printf("Error: something went wrong\n");
	exit(1);
}

void	execute(char *command, char **envp)
{
	char	**argv;
	char	*path;
	int		i;

	i = 0;
	argv = ft_split(command, ' ');
	if (!argv)
		error();
	path = ft_strjoin("/bin/", argv[0]);
	if (!path)
		error();
	if (execve(path, argv, envp) == -1)
		error();
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	free(path);
}

void	child_process(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			ft_putstr_fd("Error: fork failed\n", 2);
		if (pid1 == 0)
			child_process(argv, envp, fd);
		else
			parent_process(argv, envp, fd);
		waitpid(pid1, NULL, 0);
	}
	else
		ft_putstr_fd("Error: wrong number of arguments\n", 2);
	return (0);
}
