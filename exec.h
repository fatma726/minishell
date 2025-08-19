/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmtahmdabrahym <fatmtahmdabrahym@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:00:00 by fatmtahmdab       #+#    #+#             */
/*   Updated: 2025/08/19 18:30:00 by fatmtahmdab      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int			ms_exec_abs(
				const char *path, char *const argv[], char *const envp[]);
char		*resolve_cmd(const char *cmd);
int			wait_status_to_exitcode(int st);
int			ms_exec(char *const argv[], char *const envp[]);

typedef enum e_rtype
{
	R_IN,
	R_OUT_TRUNC,
	R_OUT_APPEND
}	t_rtype;

typedef struct s_redir
{
	t_rtype		type;
	const char	*target;
}	t_redir;

int			apply_redirs(const t_redir *rs, int n);
int			ms_exec_with_redirs(
				char *const argv[], const t_redir *rs, int n,
				char *const envp[]);
int			is_builtin(const char *s);
int			run_builtin(char *const argv[], char *const envp[]);

#endif
