/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:29:49 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/24 12:48:54 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(node **a)
{
    node    *b;
    node    *tmp;

    if (!a || !(*a) || !(*a)->next)
        return ;
    b = (*a)->next;
    tmp = b->next;
    b->next = (*a);
    b->prev = NULL;
    (*a)->next = tmp;
    (*a)->prev = b;
    if (tmp)
        tmp->prev = (*a);
    (*a) = b;
}

void sa(node **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void sb(node **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void ss(node **a, node **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}