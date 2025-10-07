/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:30:39 by mbelkass          #+#    #+#             */
/*   Updated: 2025/10/04 00:25:36 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int     ft_strlen_pro(char *str)
{
    int i;
    int len = 0;

    i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t')
            len++;
        i++;
    }
    return (len + 2);
}

char    *store_textures(int i, int j, char **all)
{
    int x;
    char *texture;
    int a = i;
    int b = j;

    j = j + 2;
    while (all[i][j] && (all[i][j] == ' ' || all[i][j] == '\t'))
        j++;
    if (all[i][j] == '\0')
        return NULL;
    if (all[i][j] != '.' || all[i][j + 1] != '/')
        return NULL;
    int start = j;
    int end = start;
    while (all[i][end] && all[i][end] != ' ' && all[i][end] != '\t' && all[i][end] != '\n')
        end++;
    texture = malloc(2 + 1 + (end - start) + 1);
    if (!texture)
        return NULL;
    texture[0] = all[a][b];
    texture[1] = all[a][b + 1];
    texture[2] = ' ';
    x = 0;
    j = start;
    while (j < end)
        texture[3 + x++] = all[i][j++];
    while (all[i][j])
    {
        if(all[i][j] != ' ' && all[i][j] != '\t')
            return NULL;
        j++;
    }
    texture[3 + x] = '\0';
    return texture;
}

char    *store_textures_pro(int i, int j, char **all)
{
    char *texture;
    int x;
    char identifier;
    int comma_count = 0;
    
    identifier = all[i][j];
    j++;
    while (all[i][j] && (all[i][j] == ' ' || all[i][j] == '\t'))
        j++;
    if (all[i][j] == '\0')
        return NULL;
    if (all[i][j] < '0' || all[i][j] > '9')
        return NULL;
    int start = j;
    int len = 0;
    int temp = j;
    while (all[i][temp] && all[i][temp] != '\n' && all[i][temp] != ' ' && all[i][temp] != '\t')
    {
        if (all[i][temp] >= '0' && all[i][temp] <= '9')
            len++;
        else if (all[i][temp] == ',')
        {
            comma_count++;
            len++;
        }
        else
            return NULL;
        temp++;
    }
    if (comma_count != 2)
        return NULL;
    while (all[i][temp])
    {
        if (all[i][temp] != ' ' && all[i][temp] != '\t' && all[i][temp] != '\n')
            return NULL;
        temp++;
    }
    texture = malloc(sizeof(char) * (len + 3));
    if (!texture)
        return NULL;
    texture[0] = identifier;
    texture[1] = ' ';
    x = 2;
    j = start;
    while (all[i][j] && all[i][j] != '\n' && all[i][j] != ' ' && all[i][j] != '\t')
    {
        if ((all[i][j] >= '0' && all[i][j] <= '9') || all[i][j] == ',')
            texture[x++] = all[i][j];
        j++;
    }
    texture[x] = '\0';
    return texture;
}

int     check_if_textures(int i, int j, char **all, t_game *game)
{
    if (all[i][j] == '\0')
        return BAD;
    if (all[i][j] == 'N' && all[i][j + 1] == 'O')
    {
        game->NO = store_textures(i, j, all);
        if (game->NO == NULL)
            return BAD;
    }
    else if (all[i][j] == 'S' && all[i][j + 1] == 'O')
    {
        game->SO = store_textures(i, j, all);
        if (game->SO == NULL)
            return BAD;
    }
    else if (all[i][j] == 'W' && all[i][j + 1] == 'E')
    {
        game->WE = store_textures(i, j, all);
        if (game->WE == NULL)
            return BAD;
    }
    else if (all[i][j] == 'E' && all[i][j + 1] == 'A')
    {
        game->EA = store_textures(i, j, all);
        if (game->EA == NULL)
            return BAD;
    }
    else if (all[i][j] == 'F' && all[i][j + 1])
    {
        game->F = store_textures_pro(i, j, all);
        if (game->F == NULL)
            return BAD;
    }
    else if (all[i][j] == 'C' && all[i][j + 1])
    {
        game->C = store_textures_pro(i, j, all);
        if (game->C == NULL)
            return BAD;
    }
    else
        return BAD;
    return GOOD;
}

int     read_textures(char **all, t_game *game)
{
    int i = 0;
    int j = 0;
    int texture_count = 0;

    while (all[i])
    {
        j = 0;
        while (all[i][j] && (all[i][j] == ' ' || all[i][j] == '\t'))
            j++;
        
        if (all[i][j] != '\0' && all[i][j] != '\n')
        {
            if (check_if_textures(i, j, all, game) == BAD)
                return -1;
            texture_count++;
            if (texture_count == 6)
                break;
        }
        i++;
    }
    if (game->NO == NULL || game->SO == NULL || game->WE == NULL ||
        game->EA == NULL || game->F == NULL || game->C == NULL)
        return -1;
    return i; //rj3t fin w9fna fl file
}
