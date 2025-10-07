/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:15:48 by mbelkass          #+#    #+#             */
/*   Updated: 2025/10/06 22:41:59 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int     ft_strlen_map(char **all, int i)
{
    int j = 0;
    int len = 0;
    int flag = 0;
    int temp = 0;
    
    while (all[i])
    {
        j = 0;
        while (all[i][j] == ' ' || all[i][j] == '\t')
            j++;
        if (all[i][j] == '\0')
        {
            temp = i;
            while (all[temp])
            {
                int c = 0;
                while (all[temp][c])
                {
                    if (all[temp][c] != ' ' && all[temp][c] != '\n')
                    {
                        if(flag)
                            return(BAD);
                    }
                    c++;
                }
                temp++;
            }
            i++;
            continue;
        }
        flag = 1;
        while (all[i][j] && (all[i][j] == '0' || all[i][j] == '1' || all[i][j] == 'N'
                        || all[i][j] == 'S' || all[i][j] == 'E' || all[i][j] == 'W' || all[i][j] == ' '))
            j++;
        while (all[i][j] && (all[i][j] == ' ' || all[i][j] == '\t' || all[i][j] == '\n'))
            j++;
        if (all[i][j] != '\0')
            return BAD;
        if (all[i][j] == '\0')
            len++;
        i++;
    }
    return (len);
}
    


char	**read_map(char **all, int i)
{
	char	**map;
	int		j;
	int		len;
	int		x;
	int		y;

	len = ft_strlen_map(all, i);
	if (len == BAD)
		return (NULL);
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (NULL);
	x = 0;
	while (all[i] && x < len)
	{
		j = 0;
		if (all[i][j] == '\0')
		{
			i++;
			continue;
		}
		map[x] = malloc(sizeof(char) * (ft_strlen(all[i]) + 1)); 
		if (!map[x])
			return (NULL);
		y = 0;
		while (all[i][j] && (all[i][j] == '0' || all[i][j] == '1'
				|| all[i][j] == 'N' || all[i][j] == 'S'
				|| all[i][j] == 'E' || all[i][j] == 'W' || all[i][j] == ' '))
			map[x][y++] = all[i][j++];
		map[x][y] = '\0';
		x++;
		i++;
	}
	map[x] = NULL;
    if ((len) != x)
        return NULL;
	return (map);
}
