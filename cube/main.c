/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:17:55 by mbelkass          #+#    #+#             */
/*   Updated: 2025/10/06 08:23:15 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        return (ft_putstr_fd("error num of args", 2), 1);

	initializer(&game);
    check_extension(argv[1]);
    game.all = read_all(argv[1]);
	int ret;
	if ((ret =read_textures(game.all, &game))== -1)
	{
		//free everything
		free_map(game.all);
		ft_putstr_fd("wrong\n",2);
		return (1);
	}
	if ((game.map = read_map(game.all, ret + 1)) == NULL)
	{
		ft_putstr_fd("error map",2);
		exit(1);
	}
	int	z;
	z = 0;
	while (game.map[z])
	{
		printf("%s\n", game.map[z]);
		z++;
	}
	
	// printf("w9fna f ster %d\n",ret);
	printf("***and the no is : %s***\n", game.NO);
	printf("***and the so is : %s***\n", game.SO);
	printf("***and the we is : %s***\n", game.WE);
	printf("***and the ea is : %s***\n", game.EA);
	printf("***and the f is : %s***\n", game.F);
	printf("***and the c is : %s***\n", game.C);
    free_map(game.all);
    close(game.fd);
    return 0;
}
// makhsoch yjkon ster khawi west lmap wlkin coordinates hanya 