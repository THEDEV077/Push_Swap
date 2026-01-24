/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:07:35 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/24 11:48:24 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct node
{
    struct node *next;
    struct node *prev;
    int data;
    int index;
} node;

#include <unistd.h>
#include <stdlib.h>

void    sortNode(node **a);
char    **ft_split(const char *s, char c);
int     ft_atoi(const char *str, int *err);
node    *initA(char ** str, node *n);
size_t	ft_len(const int *str);
void    sa(node **a);
void    sb(node **b);
void    ss(node **a, node **b);
void    pa(node **a, node **b);
void    pb(node **a, node **b);
void    ra(node **a);
void    rb(node **b);
void    rr(node **a, node **b);
void    rra(node **a);
void    rrb(node **b);
void    rrr(node **a, node **b);
void    sort3Node(node **n);
void    sort5Node(node **a, node **b);
void    nodeToTop(node **a, int pos);
int     len(node *a);
void    chunk(node **a, node **b);
int     getSmallIndex(node *a);
int     findMinPos(node *a, int min, int max);
int     findMaxPos(node *a, int min, int max);
int     cost(node *a, int x);
int     getMaxIndexPos(node *a);

#endif