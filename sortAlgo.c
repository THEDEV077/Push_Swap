/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortAlgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:35:20 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/25 10:43:54 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_node(t_node **n)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	a = *n;
	b = (*n)->next;
	c = b->next;
	if ((a->index > b->index) && (b->index < c->index) && (c->index > a->index))
		sa(n);
	if ((a->index > b->index) && (b->index > c->index) && (c->index < a->index))
	{
		sa(n);
		rra(n);
	}
	if ((a->index > b->index) && (b->index < c->index) && (c->index < a->index))
		ra(n);
	if ((a->index < b->index) && (b->index > c->index) && (c->index > a->index))
	{
		sa(n);
		ra(n);
	}
	if ((a->index < b->index) && (b->index > c->index) && (c->index < a->index))
		rra(n);
}

static int	getsmallindex(t_node *a)
{
	int	i;
	int	x;
	int	min;
	int	pos;

	i = 0;
	if (!a)
		return (-1);
	min = a->index;
	while (a)
	{
		x = a->index;
		if (x <= min)
		{
			min = x;
			pos = i;
		}
		a = a->next;
		i++;
	}
	return (pos);
}

void	node_to_top(t_node **a, int pos)
{
	int	l;
	int	rev;

	l = len(*a);
	if (pos <= l / 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		rev = l - pos;
		while (rev > 0)
		{
			rra(a);
			rev--;
		}
	}
}

void	node_to_top_b(t_node **a, int pos)
{
	int	l;
	int	rev;

	l = len(*a);
	if (pos <= l / 2)
	{
		while (pos > 0)
		{
			rb(a);
			pos--;
		}
	}
	else
	{
		rev = l - pos;
		while (rev > 0)
		{
			rrb(a);
			rev--;
		}
	}
}

void	sort5node(t_node **a, t_node **b)
{
	int	i;

	i = getsmallindex(*a);
	node_to_top(a, i);
	pb(a, b);
	i = getsmallindex(*a);
	node_to_top(a, i);
	pb(a, b);
	sort_3_node(a);
	pa(a, b);
	pa(a, b);
}
