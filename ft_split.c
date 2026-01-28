/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <ysahnoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:17:11 by ysahnoun          #+#    #+#             */
/*   Updated: 2026/01/25 18:58:14 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(const char *str, char c)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	while (str[i] && str[i] == c)
		i++;
	word = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && word == 0)
		{
			count++;
			word = 1;
		}
		else if (str[i] == c)
			word = 0;
		i++;
	}
	return (count);
}

static void	*free_split(char **res, int w)
{
	while (w > 0)
		free(res[--w]);
	free(res);
	return (NULL);
}

static char	*get_word(const char *s1, int s, int e)
{
	char	*str;
	int		len;
	int		i;

	len = e - s;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[s + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	fill_words(char **res, const char *s, char c, int len)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (w < len && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		if (i < j)
		{
			res[w] = get_word(s, i, j);
			if (!res[w++])
				return (0);
			i = j;
		}
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		len;

	if (!s)
		return (NULL);
	len = count_word(s, c);
	res = malloc((len + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (!fill_words(res, s, c, len))
		return (free_split(res, len));
	res[len] = NULL;
	return (res);
}
