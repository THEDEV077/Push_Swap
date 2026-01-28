/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:07:35 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/26 22:30:07 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
	int				index;
}	t_node;

void	sort_node(t_node **a);
char	**ft_split(const char *s, char c);
int		ft_atoi(const char *str, int *err);
t_node	*init_a(char **str, t_node *n);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	sort_3_node(t_node **n);
void	sort5node(t_node **a, t_node **b);
void	node_to_top(t_node **a, int pos);
int		len(t_node *a);
void	chunk(t_node **a, t_node **b);
int		find_min_pos(t_node *a, int min, int max);
int		find_max_pos(t_node *a, int min, int max);
int		cost(t_node *a, int x);
int		get_max_index_pos(t_node *a);
void	free_str(char **str);
void	print_erreur(void);
int		is_dup(t_node *a);
int		is_empty(t_node *a);
int		is_sorted(t_node *a);
void	free_stack(t_node *a);
void	node_to_top_b(t_node **a, int pos);
void	error_exit(t_node *a);
void	error_exit_str(char **str);

#endif
