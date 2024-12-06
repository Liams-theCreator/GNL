/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:49:29 by imellali          #+#    #+#             */
/*   Updated: 2024/12/06 14:23:56 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    char *result;

    fd = open("text.txt", O_RDONLY);
	if (!fd)
		printf("invalid file descriptor");
   	while ((result = get_next_line(fd)))
	{
		printf("%s", result);
		free(result);
		result = NULL;
	}
	close(fd);
    return (0);
}
