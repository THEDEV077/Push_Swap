/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:06:46 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/24 14:01:35 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*delete_top(t_node **a)
{
	t_node	*tmp;

	if (!a || !*a)
		return (NULL);
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	return (tmp);
}

static void	add_node_top(t_node **a, t_node *n)
{
	if (!a || !n)
		return ;
	n->next = *a;
	n->prev = NULL;
	if (*a)
		(*a)->prev = n;
	*a = n;
}

static void	push(t_node **a, t_node **b)
{
	t_node	*tmp;

	tmp = delete_top(a);
	add_node_top(b, tmp);
}

void	pa(t_node **a, t_node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
