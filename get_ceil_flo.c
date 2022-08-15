/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ceil_flo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:43:39 by hskowron          #+#    #+#             */
/*   Updated: 2022/06/28 17:16:42 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_c(char *buf, t_game *game)
{
	int	x;

	x = 0;
	while (buf[x] == ' ')
		x++;
	if (game->map_info->ceiling == 0)
		game->map_info->ceiling = get_colours(&buf[x], game);
	else
		err_exit("Invalid input", game);
	game->map_info->collected++;
}

void	get_f(char *buf, t_game *game)
{
	int	x;

	x = 0;
	while (buf[x] == ' ')
		x++;
	if (game->map_info->floor == 0)
		game->map_info->floor = get_colours(&buf[x], game);
	else
		err_exit("Invalid input", game);
	game->map_info->collected++;
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}
