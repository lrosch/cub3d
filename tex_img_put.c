/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_img_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:08:57 by lrosch            #+#    #+#             */
/*   Updated: 2022/06/28 16:20:53 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	tex_img_put_n(t_game *game, int height, int offset)
{
	int			y;
	int			start;

	if (height < WINDOWHEIGHT)
		start = (WINDOWHEIGHT - height) * 0.5;
	else
		start = 0;
	y = 0;
	colour_c_f(game, start, height);
	game->j = 0;
	if (height <= WINDOWHEIGHT)
		scale_texture(game->north, height, offset, game);
	else
		scale_big_texture(game->north, height, offset, game);
	game->img_pos++;
	if (game->img_pos == WINDOWWIDTH)
		game->img_pos = 0;
	game->last = 'N';
}

void	tex_img_put_w(t_game *game, int height, int offset)
{
	int			y;
	int			start;

	if (height < WINDOWHEIGHT)
		start = (WINDOWHEIGHT - height) * 0.5;
	else
		start = 0;
	y = 0;
	colour_c_f(game, start, height);
	game->j = 0;
	if (height <= WINDOWHEIGHT)
		scale_texture(game->west, height, offset, game);
	else
		scale_big_texture(game->west, height, offset, game);
	game->img_pos++;
	if (game->img_pos == WINDOWWIDTH)
		game->img_pos = 0;
	game->last = 'W';
}

void	tex_img_put_e(t_game *game, int height, int offset)
{
	int			y;
	int			start;

	if (height < WINDOWHEIGHT)
		start = (WINDOWHEIGHT - height) * 0.5;
	else
		start = 0;
	y = 0;
	colour_c_f(game, start, height);
	game->j = 0;
	if (height <= WINDOWHEIGHT)
		scale_texture(game->east, height, offset, game);
	else
		scale_big_texture(game->east, height, offset, game);
	game->img_pos++;
	if (game->img_pos == WINDOWWIDTH)
		game->img_pos = 0;
	game->last = 'E';
}

void	tex_img_put_s(t_game *game, int height, int offset)
{
	int			y;
	int			start;

	if (height < WINDOWHEIGHT)
		start = (WINDOWHEIGHT - height) * 0.5;
	else
		start = 0;
	y = 0;
	colour_c_f(game, start, height);
	game->j = 0;
	if (height <= WINDOWHEIGHT)
		scale_texture(game->south, height, offset, game);
	else
		scale_big_texture(game->south, height, offset, game);
	game->img_pos++;
	if (game->img_pos == WINDOWWIDTH)
		game->img_pos = 0;
	game->last = 'S';
}
