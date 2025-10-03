/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:30:39 by mbelkass          #+#    #+#             */
/*   Updated: 2025/10/03 05:14:28 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../cub3d.h"

// int     ft_strlen_pro(char *str)
// {
//     int i;
//     int len;

//     i = 0;
//     len = 0;
//     while (str[i])
//     {
//         if (str[i] != ' ' && str[i] != '\t')
//             len++;
//         i++;
//     }
//     return (len + 2);
// }

// char      *store_textures(int i, int j, char **all)
// {
//     int x;
//     char *texture;

//     x = 5;
//     int a = i;
//     int b = j;
//     int len = ft_strlen_pro(all[i]);
    
//     j = j + 2;
//     texture = malloc (sizeof(char) * (len + 1));
//     texture[0] = all[a][b];
//     texture[1] = all[a][b + 1];
//     texture[2] = ' ';
//     texture[3] = '.';
//     texture[4] = '/';
//     printf("the len im malloc is %d",len);
//     while (all[i][j] && (all[i][j] == ' ' || all[i][j] == '\t'))
//     {
//         j++;
//     }
//     if (all[i][j] == '\0')
//         return NULL;
//     if (all[i][j] == '.' && all[i][j + 1] == '/')
//     {
//         j = j + 2;
        
//         while (all[i][j])
//         {
//             texture[x] = all[i][j];
//             j++;
//             x++;
//         }
//         texture[x] = '\0';
//     }
//     else
//     {
//         return NULL;
//     }
//     return (texture);
// }

// int     check_if_textures(int i, int j, char **all, t_game *game)
// {
//     if (all[i][j] == 'N' && all[i][j + 1] == 'O')
//     {
//         game->NO = store_textures(i, j, all);
//     }
//     return 1;
//     // else if (all[i][j] == 'S' && all[i][j + 1] == 'O')
//     // {
        
//     // }
//     // else if (all[i][j] == 'E' && all[i][j + 1] == 'A')
//     // {
        
//     // }
//     // else if (all[i][j] == 'F')
//     // {
        
//     // }
//     // else if (all[i][j] == 'C')
//     // {
        
//     // }
//     // else
//     // {
//     //     printf("error textures");
//     //     return BAD;//edit that exit func that frees and exits eandk tnsa
//     // }
// }

// int     read_textures(char **all, t_game *game)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     while (all[i])
//     {
//         j = 0;
//         while (all[i][j] && (all[i][j] == ' ' || all[i][j] == '\t'))
//             j++;
//         if (all[i][j] != '\0')
//             check_if_textures(i, j, all, game);
//         i++;
//     }
//     return 1;
// }

#include "../cub3d.h"
#include <stdio.h>
#include <stdlib.h>

int ft_strlen_pro(char *str)
{
    int i = 0;
    int len = 0;

    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t')
            len++;
        i++;
    }
    return (len + 2);
}

char *store_textures(int i, int j, char **all)
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
    while (all[i][end] && all[i][end] != ' ' && all[i][end] != '\t')
        end++;
    // printf("the len is %d\n", (2 + 1 + (end - start) + 1));
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
    texture[3 + x] = '\0';
    return texture;
}

int check_if_textures(int i, int j, char **all, t_game *game)
{
    if (all[i][j] == 'N' && all[i][j + 1] == 'O')
        game->NO = store_textures(i, j, all);
    else if (all[i][j] == 'S' && all[i][j + 1] == 'O')
        game->SO = store_textures(i, j, all);
    else if (all[i][j] == 'W' && all[i][j + 1] == 'E')
        game->SO = store_textures(i, j, all);
    else if (all[i][j] == 'E' && all[i][j + 1] == 'A')
        game->SO = store_textures(i, j, all);
    else
        return BAD;
    return GOOD;
}

int read_textures(char **all, t_game *game)
{
    int i = 0;
    int j = 0;

    while (all[i])
    {
        j = 0;
        while (all[i][j] && (all[i][j] == ' ' || all[i][j] == '\t'))
            j++;
        if (all[i][j] != '\0')
        {
            if (check_if_textures(i, j, all, game) == BAD)
                return -1;
        }
        i++;
    }
    return 1;
}
