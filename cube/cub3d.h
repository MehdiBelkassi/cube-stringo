/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:09:52 by mbelkass          #+#    #+#             */
/*   Updated: 2025/10/07 02:18:59 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GOOD -99
#define BAD -88


typedef struct s_game
{
    char    **map;
    char    **all;
    int     fd;
    char    *NO;
    char    *SO;
    char    *EA;
    char    *F;
    char    *C;
    char    *WE;
    int     N_count;
    int     S_count;
    int     E_count;
    int     W_count;
} t_game;

char    **read_all(char *file);
void	free_map(char **map);
size_t	ft_strcspn(const char *s, const char *reject);
void	check_extension(char *file);
void	ft_putstr_fd(char *s, int fd);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     read_textures(char **all, t_game *game);
char    **read_map(char **all, int i);
void	initializer(t_game *game);
void	free_textures(t_game *game);


#endif