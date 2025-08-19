/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmtahmdabrahym <fatmtahmdabrahym@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:00:00 by fatmtahmdab       #+#    #+#             */
/*   Updated: 2025/08/19 18:47:03 by fatmtahmdab      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static int	open_file(const t_redir *r)
{
	if (r->type == R_IN)
		return (open(r->target, O_RDONLY));
	if (r->type == R_OUT_TRUNC)
		return (open(r->target, O_WRONLY | O_CREAT | O_TRUNC, 0644));
	return (open(r->target, O_WRONLY | O_CREAT | O_APPEND, 0644));
}

static int	redirect_fd(int fd, t_rtype type)
{
	int		dest;

	dest = STDOUT_FILENO;
	if (type == R_IN)
		dest = STDIN_FILENO;
	if (dup2(fd, dest) < 0)
	{
		perror("dup2");
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int	apply_redirs(const t_redir *rs, int n)
{
	int		i;
	int		fd;

	i = 0;
	while (i < n)
	{
		fd = open_file(&rs[i]);
		if (fd < 0)
		{
			perror(rs[i].target);
			return (-1);
		}
		if (redirect_fd(fd, rs[i].type) < 0)
			return (-1);
		i++;
	}
	return (0);
}

static void	exec_child_with_redirs(
	char *const argv[], const t_redir *rs, int count, char *const envp[])
{
	char	*path;

	if (rs && count > 0 && apply_redirs(rs, count) < 0)
		_exit(1);
	path = resolve_cmd(argv[0]);
	if (!path)
		_exit(127);
	execve(path, (char *const *)argv, envp);
	perror("execve");
	free(path);
	_exit(126);
}

int	ms_exec_with_redirs(
	char *const argv[], const t_redir *rs, int count, char *const envp[])
{
	pid_t	pid;
	int		st;

	if (!argv || !argv[0])
		return (0);
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
		exec_child_with_redirs(argv, rs, count, envp);
	if (waitpid(pid, &st, 0) < 0)
	{
		perror("waitpid");
		return (1);
	}
	return (wait_status_to_exitcode(st));
}
