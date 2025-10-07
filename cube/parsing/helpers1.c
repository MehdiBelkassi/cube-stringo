/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:54:22 by mbelkass          #+#    #+#             */
/*   Updated: 2025/10/07 03:00:18 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initializer(t_game *game)
{
	game->NO = NULL;
    game->SO = NULL;
    game->WE = NULL;
    game->EA = NULL;
    game->F = NULL;
    game->C = NULL;
    game->all = NULL;
	game->N_count = 0;
    game->S_count = 0;
    game->E_count = 0;
    game->W_count = 0;
}

void	free_textures(t_game *game)
{
	if (game->NO)
		free(game->NO);
	if (game->SO)
		free(game->SO);
	if (game->EA)
		free(game->EA);
	if (game->F)
		free(game->F);
	if (game->C)
		free(game->C);
	if (game->WE)
		free(game->WE);
}
