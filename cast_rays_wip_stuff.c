/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_wip_stuff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:58:22 by lrosch            #+#    #+#             */
/*   Updated: 2022/06/28 15:59:30 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays(t_game *game)
{
	cast_rays_positive(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame->mlx_img, 0, 0);
}

void	rotate_reverse(t_game *game)
{
	int	i;

	game->temp_x = game->or->x;
	game->temp_y = game->or->y;
	i = 0;
	while (i < WINDOWWIDTH / 2)
	{
		game->temp_y = sin(-1 * (1.0 / game->deg_mul) * PI / 180)
			* game->temp_x + cos(-1 * (1.0 / game->deg_mul)
				* PI / 180) * game->temp_y;
		game->temp_x = cos(-1 * (1.0 / game->deg_mul) * PI / 180)
			* game->temp_x - sin(-1 * (1.0 / game->deg_mul)
				* PI / 180) * game->temp_y;
		i++;
	}
}

void	rotate_forward(t_game *game)
{
	game->temp_y = sin(1 * (1.0 / game->deg_mul) * PI / 180)
		* game->temp_x + cos(1 * (1.0 / game->deg_mul)
			* PI / 180) * game->temp_y;
	game->temp_x = cos(1 * (1.0 / game->deg_mul) * PI / 180)
		* game->temp_x - sin(1 * (1.0 / game->deg_mul)
			* PI / 180) * game->temp_y;
	game->temp_deg += 1 * (1.0 / game->deg_mul);
}

void	cast_rays_positive(t_game *game)
{
	int	i;
	int	j;

	rotate_reverse(game);
	j = 0;
	i = -1 * ((WINDOWWIDTH / 2) - 1);
	game->temp_deg = -30;
	while (i <= WINDOWWIDTH / 2)
	{
		rotate_forward(game);
		while (1)
		{
			if (game->map[(int)(((game->py + (game->temp_y * j))) / game->size)]
				[(int)(((game->px + (game->temp_x * j))) / game->size)] == '1')
			{
				draw_wall(game, (game->py + (game->temp_y * j)),
					(game->px + (game->temp_x * j)), game->temp_deg);
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_wall(t_game *game, int wall_y, int wall_x, int column)
{
	double	length;
	int		height;
	int		x;
	char	tex;

	x = 0;
	length = hypot((game->px - wall_x), (game->py - wall_y));
	length = length * cos(game->temp_deg * PI / 180);
	height = (game->size / length) * game->p_dis * MUL;
	tex = examine_ray(wall_x, wall_y, game, column);
	if (tex == 'N')
		tex_img_put_n(game, height, (int)(wall_x) % game->size);
	else if (tex == 'S')
		tex_img_put_s(game, height, (int)(wall_x) % game->size);
	else if (tex == 'E')
		tex_img_put_e(game, height, (int)(wall_y) % game->size);
	else if (tex == 'W')
		tex_img_put_w(game, height, (int)(wall_y) % game->size);
}
