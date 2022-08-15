/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:25:47 by lrosch            #+#    #+#             */
/*   Updated: 2022/07/04 16:57:11 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player_pos(t_game *game)
{
	int	i;
	int	j;
	int	b;

	b = 0;
	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'W' || game->map[i][j] == 'N' ||
			game->map[i][j] == 'S' || game->map[i][j] == 'E')
			{
				b = get_orientation(game, game->map[i][j]);
				game->py = (i * game->size) + (game->size / 2);
				game->px = (j * game->size) + (game->size / 2);
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (b == 0)
		err_exit("Invalid input", game);
}

int	get_orientation(t_game *game, char c)
{
	if (c == 'E')
	{
		game->or->x = 1;
		game->or->y = 0;
		game->degree = 90;
	}
	else if (c == 'N')
	{
		game->or->x = 0;
		game->or->y = -1;
		game->degree = 0;
	}
	else if (c == 'S')
	{
		game->or->x = 0;
		game->or->y = 1;
		game->degree = 180;
	}
	else if (c == 'W')
	{
		game->or->x = -1;
		game->or->y = 0;
		game->degree = 270;
	}
	return (1);
}
