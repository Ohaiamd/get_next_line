/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:37:11 by ohaimad           #+#    #+#             */
/*   Updated: 2022/11/11 23:47:15 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (free((void *)s1), str);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
char	*ft_strdup(const char *s1)
{
	char	*s;
	char	*str;
	size_t	i;
	size_t	x;

	s = (char *)s1;
	i = 0;
	x = ft_strlen(s) + 1;
	str = malloc(x);
	if (str == 0)
		return (NULL);
	while (s[i] && i <= x)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}