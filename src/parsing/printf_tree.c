/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:39:35 by akhobba           #+#    #+#             */
/*   Updated: 2024/08/20 16:11:17 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_generate_spaces(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf(" ");
		i++;
	}
}

void ft_printf_link(t_link *link)
{
	t_link *tmp = link;
	while (tmp)
	{
		printf("tmp->command: %s\n", tmp->command);
		tmp = tmp->next;
	}
}
void ft_print_cmd(t_tree *tree)
{
	char **tmp;
	int i;
	t_redirection *redi;

	tmp = tree->cmd->argv;
	i = 0;
	// potentional segfault here
	printf("str: %s type :%d", tree->cmd->argv[0], tree->type);
	while(tmp[i])
	{
		printf("  args :%s", tmp[i]);
		i++;
	}
	redi = tree->redirection;
	while(redi)
	{
		printf("  redi :%s type: %d", redi->file, redi->identifier);
		redi = redi->next;
	}
}

void	ft_printf_tree(t_tree *tree, int space, int option)
{
	if (tree)
	{
		ft_generate_spaces(space);
		ft_print_cmd(tree);
			printf("\n");
			ft_generate_spaces(space);
			if (option == 2)
				ft_generate_spaces(20);
			printf("    /             \\");
		if (option)
			printf("\n");
	}
	if (tree->left)
	{
		space += 10;
		// printf("\n");
		option = 0;
		ft_printf_tree(tree->left, space, option);
	}
	if (tree->right)
	{
		// printf("/");
		option = 1;
		ft_printf_tree(tree->right, space, option);
	}
}
