/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortAlgo1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:44:17 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/24 12:48:31 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int findMinPos(node *a, int min, int max)
{
    int i;

    i = 0;
    if (!a)
        return (-1);
    while (a)
    {
        if (a->index >= min && a->index <= max)
            return (i);
        a = a->next;
        i++;
    }
    return (-1);
}

int findMaxPos(node *a, int min, int max)
{
    int i;

    if (!a)
        return (-1);
    i = len(a) - 1;
    while (a->next)
        a = a->next;
    while (a)
    {
        if (a->index >= min && a->index <= max)
            return (i);
        a = a->prev;
        i--;
    }
    return (-1);
}

int cost(node *a, int x)
{
    int l;

    l = len(a);
    if (x <= l / 2)
        return (x);
    else
        return (l - x);
}

int getMaxIndexPos(node *a)
{
    int max;
    int i;
    int pos;

    i = 0;
    max = a->index;
    pos = 0;
    while (a)
    {
        if (a->index > max)
        {
            max = a->index;
            pos = i;
        }
        i++;
        a = a->next;
    }
    return (pos);
}