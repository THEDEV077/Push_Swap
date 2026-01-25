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

static t_node	*create_node(char *data)
{
	t_node	*a;
	int		err;

	a = malloc(sizeof(t_node));
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

static t_node	*add_nodes(char **str, int i, t_node *n)
{
	t_node	*a;

	while (str[i])
	{
		a = create_node(str[i]);
		if (!a)
			return (NULL);
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
		n = create_node(str[0]);
		if (!n)
			return (NULL);
		i++;
	}
	s = n;
	while (n->next != NULL)
		n = n->next;
	if (!add_nodes(str, i, n))
	{
		free_stack(s);
		return (NULL);
	}
	return (s);
}
