/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by oouaadic          #+#    #+#             */
/*   Updated: 2024/08/29 18:03:37 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "parsing.h"

char	*get_last_line(void)
{
	char	*line;
	char	*last_line;

	if (g_data.hfd == -1)
		return (NULL);
	last_line = NULL;
	line = get_next_line(g_data.hfd);
	while (line)
	{
		free(last_line);
		last_line = line;
		line = get_next_line(g_data.hfd);
	}
	if (last_line)
		last_line[strlen(last_line) - 1] = 0;
	return (last_line);
}

bool	isempty(char *line)
{
	while (*line == ' ' || *line == '\t' || *line == '\n')
		line++;
	if (*line)
		return (false);
	return (true);
}

void	ft_add_history(char *line)
{
	static char	*last_line = NULL;

	if (!last_line)
		last_line = get_last_line();
	if ((last_line && !strcmp(last_line, line)) || isempty(line))
		return ;
	free(last_line);
	last_line = ft_strdup(line);
	add_history(line);
	if (g_data.hfd == -1)
		return ;
	return (dprintf(g_data.hfd, "%s\n", line), (void) NULL);
}

void	restore_history(void)
{
	char	*line;

	if (access(".minishell_history", F_OK) != -1)
	{
		if (access(".minishell_history", R_OK) == -1)
			unlink(".minishell_history");
		else if (access(".minishell_history", W_OK) == -1)
			unlink(".minishell_history");
	}
	g_data.hfd = open(".minishell_history", O_CREAT | O_RDWR | O_APPEND, 0644);
	if (g_data.hfd == -1)
		return ;
	line = get_next_line(g_data.hfd);
	while (line)
	{
		line[strlen(line) - 1] = 0;
		add_history(line);
		free(line);
		line = get_next_line(g_data.hfd);
	}
	return ;
}
