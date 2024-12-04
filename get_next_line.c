/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:20:33 by imellali          #+#    #+#             */
/*   Updated: 2024/12/04 23:29:30 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*buf;
	char		temp[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;
	int			byter;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	while ((byter = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[byter] = '\0';
		buf = ft_strjoin(buf, temp);
		if (ft_strchr(buf, '\n'))
			break;
	}

	if (!buf || *buf == '\0')
		return (NULL);

	newline = ft_strchr(buf, '\n');
	if (newline)
	{
		line = ft_substr(buf, 0, newline - buf + 1);
		buf = ft_strdup(newline + 1);
		return (line);
	}
	line = ft_strdup(buf);
	free(buf);
	buf = NULL;
	return (line);
}
