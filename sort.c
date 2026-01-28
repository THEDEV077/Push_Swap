/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:00:35 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/25 18:59:29 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len(t_node *a)
{
	int	l;

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

static int	*tri_tab(int *tab, size_t l)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while (i < l)
	{
		j = i + 1;
		while (j < l)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

static int	get_index(int *tab, int x, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		if (tab[i] == x)
			return (i);
		i++;
	}
	return (-1);
}

static void	index_t_node(t_node **a, int *tab, int l)
{
	t_node	*b;
	int		i;

	b = *a;
	while (b)
	{
		i = get_index(tab, b->data, l);
		b->index = i;
		b = b->next;
	}
}

void	sort_node(t_node **a)
{
	int		i;
	int		l;
	int		*tab;
	t_node	*tmp;

	if (!a || !(*a))
		return ;
	l = len(*a);
	tab = malloc(sizeof(int) * (l));
	if (!tab)
		return ;
	tmp = *a;
	i = 0;
	while (tmp)
	{
		tab[i++] = tmp->data;
		tmp = tmp->next;
	}
	tab = tri_tab(tab, l);
	index_t_node(a, tab, l);
	free(tab);
}
