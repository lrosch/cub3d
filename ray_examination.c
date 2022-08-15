/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_examination.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:53:23 by lrosch            #+#    #+#             */
/*   Updated: 2022/06/28 15:55:47 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	examine_ray(int wall_x, int wall_y, t_game *game, double temp_deg)
{
	char	arr[2];
	int		i;

	i = further_examination(wall_x, wall_y, game, arr);
	if (i == 0)
		return (game->last);
	if (i == 1)
		return (arr[0]);
	return (case_distinction(game, temp_deg, arr));
}

int	case_distinction(t_game *game, double temp_deg, char *arr)
{
	if (arr[0] == 'N')
	{
		if ((game->degree + (int)temp_deg) <= 90
			|| (game->degree + (int)temp_deg) >= 270)
			return ('N');
		else
			return (arr[1]);
	}
	if (arr[0] == 'S')
	{
		if ((game->degree + (int)temp_deg) <= 90
			|| (game->degree + (int)temp_deg) >= 270)
			return (arr[1]);
		else
			return ('S');
	}
	return (-1);
}

int	further_examination(int wall_x, int wall_y, t_game *game, char *arr)
{
	int	i;

	i = 0;
	if (game->map[(wall_y + 1) / game->size][wall_x / game->size] != '1')
	{
		arr[i] = 'N';
		i++;
	}
	if (game->map[(wall_y - 1) / game->size][wall_x / game->size] != '1')
	{
		arr[i] = 'S';
		i++;
	}
	if (game->map[(wall_y) / game->size][(wall_x + 1) / game->size] != '1')
	{
		arr[i] = 'W';
		i++;
	}
	if (game->map[(wall_y) / game->size][(wall_x - 1) / game->size] != '1')
	{
		arr[i] = 'E';
		i++;
	}
	return (i);
}
