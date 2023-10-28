/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:53:17 by lsaumon           #+#    #+#             */
/*   Updated: 2023/10/28 16:35:39 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *) s)[i] = c;
		i++;
	}
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return ((char *)0);
		i++;
	}
	return ((char *) &s[i]);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;

	if (!nmemb || !size)
		return (malloc(0));
	if ((nmemb * size) / size != nmemb)
		return (NULL);
	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, nmemb * size);
	return (tab);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_result;
	char	*result;

	len_s1 = 0;
	len_result = ft_strlen(s1) + ft_strlen(s2);
	result = ft_calloc(len_result + 1, sizeof(char));
	if (!result || !s1 || !s2)
		return (NULL);
	while (s1[len_s1])
	{
		result = s1[len_s1];
		len_s1++;
	}
	len_s2 = 0;
	while (s2[len_s2])
	{
		result[len_s1] = s2[len_s2];
		len_s1++;
		len_s2++;
	}
	result[len_result] = 0;
	return (result);
}
