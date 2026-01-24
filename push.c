/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:06:46 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/24 12:45:30 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static node *deleteTop(node **a)
{
    node    *b;

    if (!a || !(*a))
        return (NULL);
    b = (*a);
    (*a) = (*a)->next;
    if ((*a))
        (*a)->prev = NULL;
    return (b);
}

static void addnodeTop(node **a, node *n)
{
    if (!a || !n)
        return ;
    n->next = *a;
    n->prev = NULL;
    if (*a)
        (*a)->prev = n;
    (*a) = n;
}

void push(node **a, node **b)
{
    node    *tmp;

    tmp = deleteTop(a);
    addnodeTop(b, tmp);
}

void pa(node **a, node **b)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void pb(node **a, node **b)
{
    push(a, b);
    write(1, "pb\n", 3);
}
