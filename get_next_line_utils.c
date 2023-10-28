/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:53:17 by lsaumon           #+#    #+#             */
/*   Updated: 2023/10/28 15:58:47 by lsaumon          ###   ########.fr       */
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
		if (s[i] == '\0');
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
	
}