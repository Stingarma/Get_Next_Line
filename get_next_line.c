/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:52:55 by lsaumon           #+#    #+#             */
/*   Updated: 2023/11/01 14:06:04 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *size)
{
	char	*temp;

	temp = ft_strjoin(buffer, size);
	free(buffer);
	return (temp);
}

char	*ft_next(char *buffer)
{
	int		forward;
	int		cpy;
	char	*line;

	forward = 0;
	while (buffer[forward] && buffer[forward] != '\n')
		forward++;
	if (!buffer[forward])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - forward + 1), sizeof(char));
	if (!line)
		return (NULL);
	forward++;
	cpy = 0;
	while (buffer[forward])
	{
		line[cpy] = buffer[forward];
		cpy++;
		forward++;
	}
	free(buffer);
	return (line);
}

char	*ft_newline(char *buffer)
{
	char	*line;
	int		index;

	index = 0;
	if (!buffer[index])
		return (NULL);
	while (buffer[index] && buffer[index] != '\n')
		index++;
	line = ft_calloc(index + 2, sizeof(char));
	if (!line)
		return (NULL);
	index = 0;
	while (buffer[index] && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	if (buffer[index] && buffer[index] == '\n')
	{
		line[index] = '\n';
		index++;
	}
	return (line);
}

char	*ft_read(int fd, char *result)
{
	char	*buffer;
	int		one_read;

	if (!result)
		result = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	one_read = 1;
	if (!buffer)
		return (NULL);
	while (one_read > 0)
	{
		one_read = read(fd, buffer, BUFFER_SIZE);
		if (one_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[one_read] = 0;
		result = ft_free(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_newline(buffer);
	buffer = ft_next(buffer);
	return (line);
}
