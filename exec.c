/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmtahmdabrahym <fatmtahmdabrahym@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:00:00 by fatmtahmdab       #+#    #+#             */
/*   Updated: 2025/08/19 18:30:00 by fatmtahmdab      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	exec_child(const char *path, char *const argv[], char *const envp[])
{
	execve(path, (char *const *)argv, envp);
	perror("execve");
	_exit(126);
}

int	ms_exec_abs(const char *path, char *const argv[], char *const envp[])
{
	pid_t	pid;
	int		st;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
		exec_child(path, argv, envp);
	st = 0;
	if (waitpid(pid, &st, 0) < 0)
	{
		perror("waitpid");
		return (1);
	}
	if (WIFEXITED(st))
		return (WEXITSTATUS(st));
	if (WIFSIGNALED(st))
		return (128 + WTERMSIG(st));
	return (1);
}

int	ms_exec(char *const argv[], char *const envp[])
{
	char	*path;
	int		code;

	if (!argv || !argv[0])
		return (0);
	if (is_builtin(argv[0]))
		return (run_builtin(argv, envp));
	path = resolve_cmd(argv[0]);
	if (!path)
		return (127);
	code = ms_exec_abs(path, argv, envp);
	free(path);
	return (code);
}
