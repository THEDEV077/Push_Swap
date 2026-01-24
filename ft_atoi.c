/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:21:40 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/24 12:43:11 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sign(const char *str, int *i)
{
	int	s;

	s = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			s = -1;
		(*i)++;
	}
	return (s);
}

int	ft_atoi(const char *str, int *err)
{
	long	r;
	int		s;
	int		i;

	r = 0;
	s = 1;
	i = 0;
	*err = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	s = sign(str, &i);
	if (!(str[i] >= '0' && str[i] <= '9'))
		*err = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		if ((s == 1 && r > 2147483647) || (s == -1 && r > 2147483648))
			*err = 1;
		i++;
	}
	if (str[i] != '\0')
		*err = 1;
	return ((int)(r * s));
}
