/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:35:26 by halaqoh           #+#    #+#             */
/*   Updated: 2022/02/08 16:58:59 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_count_word(char *s, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i + 1])
				i++;
			a++;
		}
		i++;
	}
	return (a);
}

char	*ft_strndup(char *s, int n)
{
	int		k;
	char	*str;

	k = 0;
	str = malloc(n + 1);
	if (!str)
		return (0);
	while (k < n)
	{
		str[k] = s[k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

char	**mn_split(char **str, char *s, char c)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] != c && s[i + j])
				j++;
			str[a] = ft_strndup((char *) s + i, j);
			a++;
			i += j - 1;
		}
		i++;
	}
	str[a] = NULL;
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		nb_word;
	char	**str_split;

	if (!s)
		return (0);
	nb_word = ft_count_word(s, c);
	str_split = malloc((nb_word + 1) * (sizeof(char *)));
	if (!str_split)
		return (0);
	str_split = mn_split(str_split, s, c);
	return (str_split);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
