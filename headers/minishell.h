/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:00:00 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/30 11:52:02 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "parsing.h"
# include "execution.h"
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <ctype.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_cmd
{
	int		argc;
	char	**argv;
}	t_cmd;

#endif //MINISHELL_H
