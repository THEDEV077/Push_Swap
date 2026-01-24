/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:00:35 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/24 12:47:12 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int len(node *a)
{
    int l;

    l = 0;
    if (!a)
        return (0);
    while (a)
    {
        l++;
        a = a->next;
    }
    return (l);
}

static int *Tri(int *Tab)
{
    size_t  i;
    size_t  j;
    int     tmp;

    i = 0;
    while (i < ft_len(Tab))
    {
        j = i + 1;
        while (j < ft_len(Tab))
        {
            if (Tab[i] > Tab[j])
            {
                tmp = Tab[i];
                Tab[i] = Tab[j];
                Tab[j] = tmp;
            }
            j++;
        }
        i++;
    }
    return (Tab);
}

static int getIndex(int *Tab, int x)
{
    int i;

    i = 0;
    while (Tab[i])
    {
        if (Tab[i] == x)
            return (i);
        i++;
    }
    return (-1);
}

static void indexNode(node **a, int *Tab)
{
    node    *b;
    int     i;

    b = (*a);
    while (b)
    {
        i = getIndex(Tab, b->data);
        b->index = i;
        b = b->next;
    }
}

void sortNode(node **a)
{
    int     i;
    int     *Tab;
    node    *b;

    if (!a || !(*a))
        return ;
    b = *a;
    Tab = malloc(sizeof(int) * len(*a));
    i = 0;
    while (*a)
    {
        Tab[i++] = (*a)->data;
        (*a) = (*a)->next;
    }
    (*a) = b;
    Tab = Tri(Tab);
    indexNode(a, Tab);
    free(Tab);
}
