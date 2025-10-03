/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:54:22 by mbelkass          #+#    #+#             */
/*   Updated: 2025/10/03 00:19:09 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
    	free(map[i]);
    	i++;
	}
	free(map);      
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i]) 
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j]) 
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	if (fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	check_extension(char *file)
{
	int		len;

	len = ft_strlen(file);
	if (ft_strlen(&file[5]) <= 4 || ft_strncmp(&file[len - 4], ".cub", 4) != 0)
	{
		ft_putstr_fd("Error\ninvalid extension", 2);
		exit(1);
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && (s1[i] == s2[i]) && (i < n - 1))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
