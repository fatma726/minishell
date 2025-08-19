/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmtahmdabrahym <fatmtahmdabrahym@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:00:00 by fatmtahmdab       #+#    #+#             */
/*   Updated: 2025/08/19 20:19:45 by fatmtahmdab      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdio.h>

int	main(int ac, char **av, char **envp)
{
	char	**e1;
	char	**e2;
	char	**p1;
	char	**v1;

	(void)ac;
	(void)av;
	e1 = (char *[]){"echo", "hello", "world", NULL};
	printf("echo -> %d\n", ms_exec(e1, envp));
	e2 = (char *[]){"echo", "-n", "no-newline", NULL};
	printf("echo -n -> %d\n", ms_exec(e2, envp));
	printf("(should be same line)\n");
	p1 = (char *[]){"pwd", NULL};
	printf("pwd -> %d\n", ms_exec(p1, envp));
	v1 = (char *[]){"env", NULL};
	printf("env -> %d\n", ms_exec(v1, envp));
	return (0);
}
