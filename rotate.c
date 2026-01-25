/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:06:38 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/24 21:20:49 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **a)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!a || !(*a) || !(*a)->next)
		return ;
	tmp = (*a);
	tmp2 = tmp->next;
	while ((*a)->next)
		(*a) = (*a)->next;
	tmp2->prev = NULL;
	(*a)->next = tmp;
	tmp->prev = (*a);
	tmp->next = NULL;
	(*a) = tmp2;
}

void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
