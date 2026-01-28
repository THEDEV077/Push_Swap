/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:07:30 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/28 09:49:03 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node *a)
{
	t_node	*tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}

void	error_exit(t_node *a)
{
	free_stack(a);
	print_erreur();
	exit(1);
}

static int	is_only_spaces(const char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		return (1);
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && (s[i] < 9 || s[i] > 13))
			return (0);
		i++;
	}
	return (1);
}

static t_node	*fill_stack(int argc, char **argv)
{
	int		i;
	char	**str;
	t_node	*a;
	t_node	*tmp;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (is_only_spaces(argv[i]))
			error_exit(a);
		str = ft_split(argv[i], ' ');
		if (!str)
			error_exit(a);
		tmp = init_a(str, a);
		if (!tmp)
			error_exit_str(str);
		free_str(str);
		a = tmp;
		i++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc < 2)
		return (0);
	a = fill_stack(argc, argv);
	b = NULL;
	if (is_dup(a) || is_empty(a))
	{
		print_erreur();
		free_stack(a);
		exit(1);
	}
	sort_node(&a);
	if (is_sorted(a))
	{
		free_stack(a);
		exit(0);
	}
	chunk(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
