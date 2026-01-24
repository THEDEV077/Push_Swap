/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:45:30 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/24 12:42:31 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void BackToA(node **a, node **b)
{
	int	pos;

	while (*b)
	{
		pos = getMaxIndexPos(*b);
		nodeToTop(b, pos);
		pa(a, b);
	}
}

static void push_chunk(node **a, node **b, int min, int max)
{
    int x;
    int y;

    while (1)
    {
        x = findMinPos(*a, min, max);
        y = findMaxPos(*a, min, max);
        if (x == -1 && y == -1)
            break;
        if (cost(*a, x) > cost(*a, y))
            nodeToTop(a, x);
        else
            nodeToTop(a, y);
        pb(a, b);
    }
}

static void sort100Node(node **a, node **b)
{
    int i;
    int minChunk;
    int maxChunk;

    i = 0;
    while (i < 5)
    {
        minChunk = i * 20;
        maxChunk = minChunk + 19;
        push_chunk(a, b, minChunk, maxChunk);
        i++;
    }
    BackToA(a, b);
}

static void sort500Node(node **a, node **b)
{
    int i;
    int minChunk;
    int maxChunk;

    i = 0;
    while (i < 11)
    {
        minChunk = i * 45;
        maxChunk = minChunk + 44;
        push_chunk(a, b, minChunk, maxChunk);
        i++;
    }
    BackToA(a, b);
}

void chunk(node **a, node **b)
{
    int l;

    l = len(*a);
    if (l <= 1)
        return;
    else if (l == 2 && (*a)->index > (*a)->next->index)
        sa(a);
    else if (l == 2)
        return;
    else if (l == 3)
        sort3Node(a);
    else if (l == 4)
    {
        nodeToTop(a, getSmallIndex(*a));
        pb(a, b);
        sort3Node(a);
        pa(a, b);
    }
    else if (l == 5)
        sort5Node(a, b);
    else if (l <= 100)
        sort100Node(a, b);
    else
        sort500Node(a, b);
}