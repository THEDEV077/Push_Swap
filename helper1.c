/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:30:05 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/24 12:50:20 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static node *createNode(char *data)
{
    node    *a;
    int     err;

    a = malloc(sizeof(node));
    if (!a)
        return (NULL);
    a->data = ft_atoi(data, &err);
    if (err)
    {
        free(a);
        return (NULL);
    }
    a->next = NULL;
    a->prev = NULL;
    return (a);
}

static node *addnodes(char **str, int i, node *n)
{
    node    *a;

    while (str[i])
    {
        a = createNode(str[i]);
        if (!a)
            return (NULL);
        a->prev = n;
        n->next = a;
        n = a;
        i++;
    }
    return (n);
}

node    *initA(char **str, node *n)
{
    int     i;
    node    *s;
    node    *e;

    if (!str || !str[0])
        return (n);
    i = 0;
    if (n == NULL)
    {
        n = createNode(str[0]);
        if (!n)
            return (NULL);
        i++;
    }
    s = n;
    while (n->next != NULL)
        n = n->next;
    e = addnodes(str, i, n);
    if (!e)
        return (NULL);
    return (s);
}

size_t ft_len(const int *str)
{
    size_t  len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}