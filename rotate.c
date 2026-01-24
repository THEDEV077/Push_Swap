/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:06:38 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/24 12:46:30 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(node **a)
{
    node    *tmp;
    node    *tmp2;

    if (!a || !(*a))
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

void ra(node **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(node **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(node **a, node **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}