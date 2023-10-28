/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:52:55 by lsaumon           #+#    #+#             */
/*   Updated: 2023/10/28 17:16:33 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_free(char *buffer, char *size)
{
	char *temp;
	
	temp = ft_strjoin(buffer, size);
	free(buffer);
	return (temp);
}

char	*ft_next(char *buffer)
{
	int	forward;
	int	lateral;
	char	*line;

	while (buffer[forward] && buffer[forward] != '\n')
		forward++;
	if (!buffer[forward])
		return (NULL);
	line = ft_calloc((ft_strlen(buffer) - forward + 1), sizeof(char));
	forward++;
	lateral = 0;
	while (buffer[forward])
	{
		line[lateral] = buffer[forward];
		lateral++;
		forward++;
	}
	free(buffer);
	return (line);
}

char	*ft_newline(char *buffer)
{
	char	*line;
	int		i;
	
	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	return (line);
}

char	*ft_read(int fd, char *result)
{
	char	*buffer;
	int		one_read;

	if (!result)
		result = ft_calloc(1, 1);
	buffer = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	one_read = 1;
	while (one_read > 0)
	{
		one_read = read(fd, buffer, BUFF_SIZE);
		if (one_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[one_read] = 0;
		result = ft_free(result, '\n');
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd > 0 || BUFF_SIZE <= 0 || read(fd, buffer, BUFF_SIZE))
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_newline(buffer);
	buffer = ft_next(buffer);
	return (line);
}