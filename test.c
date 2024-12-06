/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:57:30 by imellali          #+#    #+#             */
/*   Updated: 2024/12/06 13:56:25 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*buf;
	char		*newline;
	char		*line;
	char		temp[BUFFER_SIZE + 1];
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// reading from file 
	while ((bytes = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[bytes] = '\0';
		buf = ft_strjoin(buf, temp);
		if ((ft_strchr(buf, '\n')))
			break ;
	}
	// if theres no more data to read (EOF reached)
	if (!buf)
		return (NULL);
	// extracting line and return it
	newline = ft_strchr(buf, '\n');
	if (newline)
	{
		line = ft_substr(buf, 0, newline - buf + 1);
		buf = ft_strdup(newline + 1);
		return (line);
	}
	// if there is no new line found , then return what I read and fetch again until found newline
	line = ft_strdup(buf);
	free(buf);
	buf = NULL;
	return (line);
}
