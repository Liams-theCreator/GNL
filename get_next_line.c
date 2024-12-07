/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:20:33 by imellali          #+#    #+#             */
/*   Updated: 2024/12/07 10:30:23 by imellali         ###   ########.fr       */
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
	if (byter == -1)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		temp[BUFFER_SIZE + 1];
	char		*newline;
	char		*data;
	char		*pt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = reading(fd, leftover, temp);
	if (!leftover || *leftover == '\0')
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	newline = ft_strchr(leftover, '\n');
	if (newline)
	{
		data = ft_substr(leftover, 0, newline - leftover + 1);
		pt = leftover;
		leftover = ft_strdup(newline + 1);
		free(pt);
		return (data);
	}
	data = ft_strdup(leftover);
	free(leftover);
	leftover = NULL;
	return (data);
}
