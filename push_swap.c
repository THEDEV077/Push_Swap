/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:07:30 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/24 13:10:20 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void PrintErreur(void)
{
    write(1, "Error\n", 6);
}

int isDup(node *a)
{
    node    *tmp1;
    node    *tmp2;

    tmp1 = a;
    while (tmp1)
    {
        tmp2 = tmp1->next;
        while (tmp2)
        {
            if (tmp2->data == tmp1->data)
                return (1);
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }
    return (0);
}

int isEmpty(node *a)
{
    int l;

    l = len(a);
    if (l == 0)
        return (1);
    else
        return (0);
}

int isSorted(node *a)
{
    if (!a)
        return (1);
    while (a && a->next)
    {
        if (a->index > a->next->index)
            return (0);
        a = a->next;
    }
    return (1);
}

void free_stack(node *a)
{
    node    *tmp;

    while (a)
    {
        tmp = a->next;
        free(a);
        a = tmp;
    }
}

void freeStr(char **str)
{
    int i;

    i = 0;
    while (str && str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}



int main(int argc, char *argv[])
{
    int     i;
    node    *a;
    node    *b;
    char    **str;

    if (argc < 2)
        return (0);
    i = 1;
    a = NULL;
    b = NULL;
    while (argv[i])
    {
        str = ft_split(argv[i], ' ');
        a = initA(str, a);
        freeStr(str);
        if (!a)
        {
            PrintErreur();
            exit(1);
        }
        i++;
    }
    if (isDup(a) || isEmpty(a))
    {
        PrintErreur();
        free_stack(a);
        exit(1);
    }
    sortNode(&a);
    if (isSorted(a))
    {
        free_stack(a);
        exit(0);
    }
    chunk(&a, &b);
    free_stack(a);
    return (0);
}
