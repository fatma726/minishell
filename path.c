/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmtahmdabrahym <fatmtahmdabrahym@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/08/19 18:39:58 by fatmtahmdab      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static char	*join_dir_cmd(const char *start, size_t dlen, const char *cmd)
{
	size_t	clen;
	char	*full;

	clen = strlen(cmd);
	full = malloc(dlen + 1 + clen + 1);
	if (!full)
		return (NULL);
	memcpy(full, start, dlen);
	full[dlen] = '/';
	memcpy(full + dlen + 1, cmd, clen);
	full[dlen + 1 + clen] = '\0';
	return (full);
}

static char	*search_in_path(const char *path, const char *cmd)
{
	const char	*p;
	const char	*start;
	char		*full;

	p = path;
	while (*p)
	{
		start = p;
		while (*p && *p != ':')
			p++;
		full = join_dir_cmd(start, (size_t)(p - start), cmd);
		if (!full)
			return (NULL);
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
		if (*p == ':')
			p++;
	}
	return (NULL);
}

char	*resolve_cmd(const char *cmd)
{
	const char	*path;

	if (cmd == NULL || *cmd == '\0')
		return (NULL);
	if (strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (strdup(cmd));
		return (NULL);
	}
	path = getenv("PATH");
	if (path == NULL)
		return (NULL);
	return (search_in_path(path, cmd));
}
