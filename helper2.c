/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:50:17 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/25 11:17:46 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_erreur(void)
{
	write(2, "Error\n", 6);
}

int	is_dup(t_node *a)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp2->data == tmp1->data)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int	is_empty(t_node *a)
{
	if (len(a) == 0)
		return (1);
	return (0);
}

int	is_sorted(t_node *a)
{
	if (!a)
		return (1);
	while (a && a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
