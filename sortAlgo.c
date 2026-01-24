/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortAlgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:35:20 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/24 12:47:55 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort3Node(node **n)
{
    node    *a;
    node    *b;
    node    *c;

    a = (*n);
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

int getSmallIndex(node *a)
{
    int i;
    int x;
    int min;
    int pos;

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

void nodeToTop(node **a, int pos)
{
    int l;

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
        while (pos < l)
        {
            rra(a);
            pos++;
        }
    }
}

void sort5Node(node **a, node **b)
{
    int i;

    i = getSmallIndex(*a);
    nodeToTop(a, i);
    pb(a, b);
    i = getSmallIndex(*a);
    nodeToTop(a, i);
    pb(a, b);
    sort3Node(a);
    pa(a, b);
    pa(a, b);
}