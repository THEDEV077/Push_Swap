/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:06:34 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/24 12:46:00 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void revrotate(node **a)
{
    node    *tmp;

    if (!a || !(*a))
        return ;
    tmp = (*a);
    while ((*a)->next)
        (*a) = (*a)->next;
    (*a)->prev->next = NULL;
    (*a)->next = tmp;
    (*a)->prev = NULL;
    tmp->prev = (*a);
}

void rra(node **a)
{
    revrotate(a);
    write(1, "rra\n", 4);
}

void rrb(node **b)
{
    revrotate(b);
    write(1, "rrb\n", 4);
}

void rrr(node **a, node **b)
{
    revrotate(a);
    revrotate(b);
    write(1, "rrr\n", 4);
}
