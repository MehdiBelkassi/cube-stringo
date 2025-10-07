/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:17:14 by mbelkass          #+#    #+#             */
/*   Updated: 2025/10/07 03:01:42 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int    count_height(char *file)
{
    int i;
    char *line;
    int fd;

    i = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (ft_putstr_fd("error: cannot open file\n", 2),-1);
    while((line = get_next_line(fd)) != NULL)
    {
        free(line);
        i++;
    }
    close(fd);
    return i;
}

void	process_line(char *line, char **all, int *i)
{
	line[ft_strcspn(line, "\n")] = '\0';

        all[*i] = line;
        if (!all[*i])
        {
            free_map(all);
            ft_putstr_fd ("error" ,2);
        }
        (*i)++;
}

char    **read_all(char *file)
{
    int height;
    char *line;
    int i;
    int fd;
    char **all;

    if ((height = count_height(file)) == -1)
    {
        ft_putstr_fd("Invalid map: empty line", 2);
        exit (1);
    }
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        ft_putstr_fd("error: cannot open file\n", 2);
        exit(1);
    }
    all = malloc(sizeof(char *) * (height + 1));
    if (!all)
        return (NULL);
    line = get_next_line(fd);
    i = 0;
    while(line)
    {
        process_line(line, all, &i);
		line = get_next_line(fd);
    }
    all[i] = NULL;
    return (all);
}
