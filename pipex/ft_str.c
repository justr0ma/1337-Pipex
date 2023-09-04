/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:00:31 by halaqoh           #+#    #+#             */
/*   Updated: 2022/02/05 15:29:38 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		b;
	int		a;

	b = 0;
	a = 0;
	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (0);
	while (s1[a])
	{
		join[a] = s1[a];
		a++;
	}
	while (s2[b])
		join[a++] = s2[b++];
	join[a] = '\0';
	return (join);
}

int	ft_strchr(char *s)
{
	int		i;
	char	*c;

	c = "PATH";
	i = 0;
	while (i < 4)
	{
		if (s[i] != c[i])
			return (0);
		i++;
	}
	return (1);
}
