/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:20:33 by imellali          #+#    #+#             */
/*   Updated: 2024/12/06 15:21:55 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == 0)
		return ((char *)&s[i]);
	return ((char *)0);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*buffer;

	i = 0;
	len = ft_strlen(s);
	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static char	*reading(int fd, char *buf, char *temp)
{
	int		byter;

	while ((byter = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[byter] = '\0';
		buf = ft_strjoin(buf, temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		temp[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = reading(fd, buf, temp);
	if (!buf || *buf == '\0')
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
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
