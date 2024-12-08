/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:49:29 by imellali          #+#    #+#             */
/*   Updated: 2024/12/08 17:36:39 by imellali         ###   ########.fr       */
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
	while ((result = get_next_line(fd)))
	{
		printf("%s", result);
		free(result);
	}
	close(fd);
    return (0);
}
