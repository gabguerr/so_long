/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabguerr <gabguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:49:45 by gabguerr          #+#    #+#             */
/*   Updated: 2024/07/30 11:58:07 by gabguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ber_file(const char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (ft_strncmp(".ber", str + len - 4, 4) == 0)
		return (true);
	return (false);
}

int	open_file(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		init_error(1);
	}
	return (fd);
}

void	get_start_coordinates(char **map, t_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i][0] != '\0')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				data->start_x = j;
				data->start_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	print_steps(void)
{
	static int	steps;

	steps++;
	ft_printf("Number of steps: %d\n", steps);
}
