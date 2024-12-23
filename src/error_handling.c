/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabguerr <gabguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:26:22 by sofia             #+#    #+#             */
/*   Updated: 2024/07/30 11:16:09 by gabguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_error(int nbr)
{
	if (nbr == 1)
	{
		ft_putstr_fd("Error\nNot enough arguments!\nPlease include .ber!\n", 2);
		exit(1);
	}
	else if (nbr == 2)
	{
		ft_putstr_fd("Error\nInvalid file type.\n.ber files only!\n", 2);
		exit(1);
	}
	else if (nbr == 3)
	{
		ft_putstr_fd("Error\nEmpty file!\n", 2);
		exit(1);
	}
	else if (nbr == 4)
	{
		ft_putstr_fd("Error\nMemory allocation failed!\ntype: objects", 2);
		exit(1);
	}
}

void	map_error(int nbr, char *line)
{
	if (nbr == 4)
	{
		ft_putstr_fd("Error\nMap is invalid!\ntype: SHAPE\n", 2);
		free(line);
		exit(1);
	}
	else if (nbr == 5)
	{
		ft_putstr_fd("Error\nMap is invalid!\ntype: BORDERS\n", 2);
		exit(1);
	}
	else if (nbr == 6)
	{
		ft_putstr_fd("Error\nMap is invalid!\ntype: SYMBOLS\n", 2);
		exit(1);
	}
	else if (nbr == 7)
	{
		ft_putstr_fd("Error\nMap is invalid!\ntype: INVALID PATH\n", 2);
		exit(1);
	}
}

void	init_error(int nbr)
{
	if (nbr == 1)
	{
		ft_putstr_fd("Error\nRead error!\n", 2);
		exit(1);
	}
	else if (nbr == 2)
	{
		ft_putstr_fd("Error\nWindow initialization failed!\n", 2);
		exit(1);
	}
}

void	error_mlx(char **map)
{
	ft_printf("%s\n", mlx_strerror(mlx_errno));
	free_map(map);
	exit(1);
}
