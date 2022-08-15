/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:10:28 by lrosch            #+#    #+#             */
/*   Updated: 2022/06/28 18:22:32 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	colour_c_f(t_game *game, int start, int height)
{
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < start)
	{
		img_pix_put(game->frame, game->img_pos, y, game->map_info->ceiling);
		y++;
	}
	y += height;
	while (y < WINDOWHEIGHT)
	{
		img_pix_put(game->frame, game->img_pos, y, game->map_info->floor);
		y++;
	}
}

void	scale_big_texture(t_img *tex, int height, int offset, t_game *game)
{
	t_img	tmp;
	double	mul;
	int		start;

	tmp.mlx_img = mlx_new_image(game->mlx, 1, height);
	tmp.addr = mlx_get_data_addr(tmp.mlx_img, &tmp.bpp,
			&tmp.line_len, &tmp.endian);
	mul = 64 / (double)height;
	start = (height - WINDOWHEIGHT) / 2;
	if ((height - WINDOWHEIGHT) % 2 == 1)
		start++;
	color_tmp(height, &tmp, tex, offset);
	cut_tmp(start, game, &tmp);
}

void	cut_tmp(int start, t_game *game, t_img *tmp)
{
	int	i;

	i = 0;
	while (i < WINDOWHEIGHT)
	{
		game->frame->addr[(((game->frame->line_len) * i) + (4 * game->img_pos))]
			= tmp->addr[(tmp->line_len * (start + i))];
		game->frame->addr[(((game->frame->line_len) * i) + (4 * game->img_pos))
			+ 1] = tmp->addr[(tmp->line_len * (start + i)) + 1];
		game->frame->addr[(((game->frame->line_len) * i) + (4 * game->img_pos))
			+ 2] = tmp->addr[(tmp->line_len * (start + i)) + 2];
		game->frame->addr[(((game->frame->line_len) * i) + (4 * game->img_pos))
			+ 3] = tmp->addr[(tmp->line_len * (start + i)) + 3];
		i++;
	}
	mlx_destroy_image(game->mlx, tmp->mlx_img);
}

void	color_tmp(int height, t_img *tmp, t_img *tex, int offset)
{
	int		y;
	double	mul_y;
	double	mul;

	mul_y = 0;
	mul = 64 / (double)height;
	y = 0;
	while (y < height)
	{
		tmp->addr[(((tmp->line_len) * y))] = tex->addr[((tex->line_len
					* (int)mul_y) + (offset * 4))];
		tmp->addr[(((tmp->line_len) * y)) + 1] = tex->addr[((tex->line_len
					* (int)mul_y) + (offset * 4)) + 1];
		tmp->addr[(((tmp->line_len) * y)) + 2] = tex->addr[((tex->line_len
					* (int)mul_y) + (offset * 4)) + 2];
		tmp->addr[(((tmp->line_len) * y)) + 3] = tex->addr[((tex->line_len
					* (int)mul_y) + (offset * 4)) + 3];
		y++;
		mul_y += mul;
	}
}

void	scale_texture(t_img *tex, int height, int offset, t_game *game)
{
	double	mul;
	int		start;
	int		y;

	y = 0;
	mul = 64 / (double)height;
	start = (WINDOWHEIGHT - height) * 0.5;
	while (y < height)
	{
		game->frame->addr[(((game->frame->line_len) * (y + start))
				+ (4 * game->img_pos))] = tex->addr
		[((tex->line_len * (int)game->j) + (offset * 4))];
		game->frame->addr[(((game->frame->line_len) * (y + start))
				+ (4 * game->img_pos)) + 1] = tex->addr
		[((tex->line_len * (int)game->j) + (offset * 4)) + 1];
		game->frame->addr[(((game->frame->line_len) * (y + start))
				+ (4 * game->img_pos)) + 2] = tex->addr
		[((tex->line_len * (int)game->j) + (offset * 4)) + 2];
		game->frame->addr[(((game->frame->line_len) * (y + start))
				+ (4 * game->img_pos)) + 3] = tex->addr
		[((tex->line_len * (int)game->j) + (offset * 4)) + 3];
		y++;
		game->j += mul;
	}
}
