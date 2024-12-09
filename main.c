/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:49:29 by imellali          #+#    #+#             */
/*   Updated: 2024/12/09 18:20:46 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    char *str, *str2, *str3;
	int fd, fd2, fd3;

	fd = open("text.txt", O_RDONLY);
	fd2 = open("text1.txt", O_RDONLY);
	fd3 = open("text2.txt", O_RDONLY);
	while (1)
	{
		if ((str = get_next_line(fd)))
		{
			printf("%s", str);
			free(str);
		}
		if ((str2 = get_next_line(fd2)))
		{
			printf("%s", str2);
			free(str2);
		}
		if ((str3 = get_next_line(fd3)))
		{
			printf("%s", str3);
			free(str3);
		}
		else
			break;
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
	while ((str2 = get_next_line(fd2)) != NULL)
	{
		printf("%s", str2);
		free(str2);
	}
	while ((str3 = get_next_line(fd3)) != NULL)
	{
		printf("%s", str3);
		free(str3);
	}
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}
