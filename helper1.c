/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:30:05 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/25 12:09:28 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_node(char *data, t_node *stack_a)
{
	t_node	*a;
	int		err;

	a = malloc(sizeof(t_node));
	if (!a)
		error_exit(stack_a);
	a->data = ft_atoi(data, &err);
	if (err)
	{
		free(a);
		error_exit(stack_a);
	}
	a->next = NULL;
	a->prev = NULL;
	return (a);
}

static t_node	*add_nodes(char **str, int i, t_node *n, t_node *stack_a)
{
	t_node	*a;

	while (str[i])
	{
		a = create_node(str[i], stack_a);
		a->prev = n;
		n->next = a;
		n = a;
		i++;
	}
	return (n);
}

t_node	*init_a(char **str, t_node *n)
{
	int		i;
	t_node	*s;

	if (!str || !str[0])
		return (n);
	i = 0;
	if (n == NULL)
	{
		n = create_node(str[0], n);
		i++;
	}
	s = n;
	while (n->next != NULL)
		n = n->next;
	add_nodes(str, i, n, s);
	return (s);
}
