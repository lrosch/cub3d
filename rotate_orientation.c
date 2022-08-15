/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_orientation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:47:12 by lrosch            #+#    #+#             */
/*   Updated: 2022/06/28 15:34:00 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_ea(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		game->or->x = cos(1 * PI / 180) * game->or->x - sin(1 * PI / 180)
			* game->or->y;
		game->or->y = sin(1 * PI / 180) * game->or->x + cos(1 * PI / 180)
			* game->or->y;
		i++;
	}
	game->degree += i;
}

void	rotate_we(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		game->or->x = cos(-1 * PI / 180) * game->or->x - sin(-1 * PI / 180)
			* game->or->y;
		game->or->y = sin(-1 * PI / 180) * game->or->x + cos(-1 * PI / 180)
			* game->or->y;
		i++;
	}
	game->degree -= i;
}

void	change_orientation(t_game *game)
{
	if (game->degree == 90 || game->degree == -270)
	{
		game->or->x = 1;
		game->or->y = 0;
	}
	else if (game->degree == 180 || game->degree == -180)
	{
		game->or->x = 0;
		game->or->y = 1;
	}
	else if (game->degree == 270 || game->degree == -90)
	{
		game->or->x = -1;
		game->or->y = 0;
	}
	else if (game->degree == 360 || game->degree == 0 || game->degree == -360)
	{
		game->or->x = 0;
		game->or->y = -1;
		if (game->degree == 360 || game->degree == -360)
			game->degree = 0;
	}
}
