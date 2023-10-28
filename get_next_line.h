/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:52:38 by lsaumon           #+#    #+#             */
/*   Updated: 2023/10/28 13:44:16 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	char			buffer[BUFF_SIZE + 1];
	struct s_list	*next;
}					t_list;

char *get_next_line(int fd);

#endif