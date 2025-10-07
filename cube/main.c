/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:17:55 by mbelkass          #+#    #+#             */
/*   Updated: 2025/10/07 02:52:07 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		search_piece(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int		check_pieces(t_game *game)
{
	int count;
	int i;
	
	count = 0;
	i = 0;
	while (game->map[i])
	{
		game->N_count += search_piece(game->map[i],'N');
		game->S_count += search_piece(game->map[i],'S');
		game->E_count += search_piece(game->map[i],'E');
		game->W_count += search_piece(game->map[i],'W');
		i++;
	}
	if (game->N_count + game->S_count + game->E_count
					+ game->W_count != 1)
		return (BAD);
	return (GOOD);
}

int main(int argc, char **argv)
{
    t_game game;
	int ret;

    if (argc != 2)
        return (ft_putstr_fd("error num of args", 2), 1);
	initializer(&game);
    check_extension(argv[1]);
    if ((game.all = read_all(argv[1])) == NULL)
		return (ft_putstr_fd("error\n", 2), 1);	
	if ((ret = read_textures(game.all, &game))== -1)
	{
		free_map(game.all);
		free_textures(&game);
		return(ft_putstr_fd("wrong textures\n",2), 1);
	}
	if ((game.map = read_map(game.all, ret + 1)) == NULL)
	{
		free_map(game.all);
		free_textures(&game);
		return(ft_putstr_fd("error map\n",2), 1);
	}
	if (check_pieces(&game) == BAD)
	{
		free_map(game.all);
		free_textures(&game);
		free_map(game.map);
		return (ft_putstr_fd("Error\ncheck pieces in map", 2), 1);
	}

	
	//the end
    free_map(game.all);
	free_map(game.map);
	free_textures(&game);
    close(game.fd);
	puts("success");
    return 0;
}
// makhsoch yjkon ster khawi west lmap wlkin coordinates hanya 