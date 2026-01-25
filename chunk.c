/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:45:30 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/25 10:43:09 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	back_to_a(t_node **a, t_node **b)
{
	int	pos;

	while (*b)
	{
		pos = get_max_index_pos(*b);
		node_to_top_b(b, pos);
		pa(a, b);
	}
}

static void	push_chunk(t_node **a, t_node **b, int min, int max)
{
	int	x;
	int	y;

	while (1)
	{
		x = find_min_pos(*a, min, max);
		y = find_max_pos(*a, min, max);
		if (x == -1 && y == -1)
			break ;
		if (cost(*a, x) <= cost(*a, y))
			node_to_top(a, x);
		else
			node_to_top(a, y);
		pb(a, b);
		if ((*b)->next && (*b)->index < (min + max) / 2)
			rb(b);
	}
}

static void	sort100node(t_node **a, t_node **b)
{
	int	i;
	int	min_chunk;
	int	max_chunk;

	i = 0;
	while (i < 7)
	{
		min_chunk = i * 15;
		max_chunk = min_chunk + 14;
		push_chunk(a, b, min_chunk, max_chunk);
		i++;
	}
	back_to_a(a, b);
}

static void	sort500node(t_node **a, t_node **b)
{
	int	i;
	int	min_chunk;
	int	max_chunk;

	i = 0;
	while (i < 15)
	{
		min_chunk = i * 35;
		max_chunk = min_chunk + 34;
		push_chunk(a, b, min_chunk, max_chunk);
		i++;
	}
	back_to_a(a, b);
}

void	chunk(t_node **a, t_node **b)
{
	int	l;

	l = len(*a);
	if (l <= 1)
		return ;
	else if (l == 2 && (*a)->index > (*a)->next->index)
		sa(a);
	else if (l == 2)
		return ;
	else if (l == 3)
		sort_3_node(a);
	else if (l == 4)
	{
		node_to_top(a, get_max_index_pos(*a));
		pb(a, b);
		sort_3_node(a);
		pa(a, b);
		ra(a);
	}
	else if (l == 5)
		sort5node(a, b);
	else if (l <= 100 && l >= 6)
		sort100node(a, b);
	else if (l > 100)
		sort500node(a, b);
}
