/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:43:23 by adam              #+#    #+#             */
/*   Updated: 2024/08/20 18:56:47 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_set_type(t_link **node, char *input)
{
	if (*node == NULL)
		return ;
	if (!ft_strncmp(input, "<", ft_strlen(input)))
		(*node)->identifier = IN;
	else if (!ft_strncmp(input, ">", ft_strlen(input)))
		(*node)->identifier = OUT;
	else if (!ft_strncmp(input, "<<", ft_strlen(input)))
		(*node)->identifier = HERDOC;
	else if (!ft_strncmp(input, ">>", ft_strlen(input)))
		(*node)->identifier = APPEND;
	else if (!ft_strncmp(input, "|", ft_strlen(input)))
		(*node)->identifier = PIPE;
	else if (!ft_strncmp(input, "||", ft_strlen(input)))
		(*node)->identifier = OR;
	else if (!ft_strncmp(input, "&&", ft_strlen(input)))
		(*node)->identifier = AND;
	else if (!ft_strncmp(input, "(", ft_strlen(input)))
		(*node)->identifier = OPEN_PAR;
	else if (!ft_strncmp(input, ")", ft_strlen(input)))
		(*node)->identifier = CLOSE_PAR;
	else
		(*node)->identifier = STR;
}

t_link	*ft_def_type(char **input)
{
	t_link	*link;
	t_link	*node;
	int		i;

	i = 0;
	link = NULL;
	while (input[i])
	{
		node = ft_dbl_lstnew(input[i]);
		ft_set_type(&node, input[i]);
		ft_dbl_lstadd_back(&link, node);
		i++;
	}
	return (link);
}

void	ft_parsing(char *input)
{
	t_link	*link;
	char	**split_input;
	t_link	*tmp;
	t_tree	*tree;

	tree = NULL;
	split_input = ft_lexer(input);
	link = ft_def_type(split_input);
	tmp = link;
	tree = ft_create_tree(&tree, tmp);
	ft_generate_spaces(20);
	ft_printf_tree(tree, 0, 2);
	printf("\n");
	ft_dbl_lstclear(&link);
}
