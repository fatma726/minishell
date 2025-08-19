/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmtahmdabrahym <fatmtahmdabrahym@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:50:00 by fatmtahmdab       #+#    #+#             */
/*   Updated: 2025/08/19 18:52:55 by fatmtahmdab      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int	bi_echo(char *const argv[])
{
	int		i;
	int		newline;
	int		first;

	i = 1;
	newline = 1;
	first = 1;
	if (argv[1] && strcmp(argv[1], "-n") == 0)
	{
		newline = 0;
		i = 2;
	}
	while (argv[i])
	{
		if (!first)
			printf(" ");
		printf("%s", argv[i]);
		first = 0;
		i++;
	}
	if (newline)
		printf("\n");
	return (0);
}

static int	bi_pwd(void)
{
	char	buf[4096];

	if (getcwd(buf, sizeof(buf)))
	{
		printf("%s\n", buf);
		return (0);
	}
	perror("pwd");
	return (1);
}

static int	bi_env(char *const envp[])
{
	int		i;

	i = 0;
	while (envp && envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}

int	is_builtin(const char *s)
{
	if (!s)
		return (0);
	if (strcmp(s, "echo") == 0)
		return (1);
	if (strcmp(s, "pwd") == 0)
		return (1);
	if (strcmp(s, "env") == 0)
		return (1);
	return (0);
}

int	run_builtin(char *const argv[], char *const envp[])
{
	if (!argv || !argv[0])
		return (0);
	if (strcmp(argv[0], "echo") == 0)
		return (bi_echo(argv));
	if (strcmp(argv[0], "pwd") == 0)
		return (bi_pwd());
	if (strcmp(argv[0], "env") == 0)
		return (bi_env(envp));
	return (1);
}
