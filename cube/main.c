/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:17:55 by mbelkass          #+#    #+#             */
/*   Updated: 2025/10/03 03:33:03 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        return (printf("error num of args"), 1);

		
    check_extension(argv[1]);

	
    game.all = read_all(argv[1]);

	read_textures(game.all, &game);
    int x = 0;
	while (game.all && game.all[x])
	{
		int y = 0;
		while (game.all[x][y])
		{
			printf("%c", game.all[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	printf("***and the no is : %s***\n", game.NO);
	
    free_map(game.all);
    close(game.fd);
    return 0;
}
// makhsoch yjkon ster khawi west lmap wlkin coordinates hanya 