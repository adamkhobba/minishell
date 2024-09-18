/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by oouaadic          #+#    #+#             */
/*   Updated: 2024/09/18 13:14:20 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

bool	builtin_echo(t_cmd *cmd)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	if (cmd->argc > 1 && !ft_strcmp(cmd->argv[1], "-n"))
	{
		n_flag = 1;
		i++;
	}
	while (i < cmd->argc)
	{
		ft_printf("%s", cmd->argv[i]);
		if (i + 1 < cmd->argc)
			ft_printf(" ");
		i++;
	}
	if (!n_flag)
		ft_printf("\n");
	return (g_data.exit_status = EXIT_SUCCESS, true);
}
