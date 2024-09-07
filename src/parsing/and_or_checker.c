/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:07:48 by adam              #+#    #+#             */
/*   Updated: 2024/09/02 13:22:22 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_errorn	ft_check_operatore(t_link *link, int target, t_errorn error)
{
	t_link	*tmp;

	tmp = link;
	while (tmp)
	{
		if (tmp->identifier == target)
		{
			if (!tmp->next)
				return (error);
			if (!tmp->prev)
				return (error);
		}
		tmp = tmp->next;
	}
	return (NONE);
}

t_errorn	ft_check_and_or(t_link *link)
{
	t_errorn	error;

	error = ft_check_operatore(link, AND, ERROR_AND);
	if (error)
		return (error);
	error = ft_check_operatore(link, OR, ERROR_OR);
	if (error)
		return (error);
	return (NONE);
}
