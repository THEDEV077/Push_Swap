/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:06:34 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/25 10:46:15 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	revrotate(t_node **a)
{
	t_node	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->next = *a;
	tmp->prev = NULL;
	(*a)->prev = tmp;
	*a = tmp;
}

void	rra(t_node **a)
{
	revrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	revrotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	revrotate(a);
	revrotate(b);
	write(1, "rrr\n", 4);
}
