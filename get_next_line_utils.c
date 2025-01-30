/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:24:39 by luevange          #+#    #+#             */
/*   Updated: 2025/01/30 18:38:39 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s1)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	c1;

	c1 = (unsigned char)c;
	while (*str)
	{
		if (*str == c1)
			return ((char *)str);
		str++;
	}
	if (c1 == '\0')
		return ((char *)str);
	return (NULL);
}

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char const		*tmp;
	char			*s2;
	unsigned int	i;

	i = 0;
	if (start > ft_strlen(s))
	{
		s2 = (char *)malloc(1);
		s2[0] = 0;
		return (s2);
	}
	tmp = &(s[start]);
	if (len < ft_strlen(tmp))
		s2 = (char *)malloc(len + 1);
	else
		s2 = (char *)malloc(ft_strlen(tmp) + 1);
	while (*tmp && i < len)
	{
		s2[i] = *tmp;
		tmp++;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strdup(const char *s)
{
	size_t	c;
	int		i;
	char	*s2;

	i = 0;
	c = ft_strlen(s);
	s2 = malloc(c + 1);
	if (!s2)
		return (NULL);
	while (s[i] != '\0')
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
