/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:08:17 by lrosch            #+#    #+#             */
/*   Updated: 2022/06/28 18:05:17 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_walls(t_game *game)
{
	check_xpm(game);
	game->north->mlx_img = mlx_xpm_file_to_image(game->mlx,
			game->map_info->north, &game->size, &game->size);
	game->south->mlx_img = mlx_xpm_file_to_image(game->mlx,
			game->map_info->south, &game->size, &game->size);
	game->east->mlx_img = mlx_xpm_file_to_image(game->mlx,
			game->map_info->east, &game->size, &game->size);
	game->west->mlx_img = mlx_xpm_file_to_image(game->mlx,
			game->map_info->west, &game->size, &game->size);
	game->north->addr = mlx_get_data_addr(game->north->mlx_img,
			&game->north->bpp, &game->north->line_len, &game->north->endian);
	game->south->addr = mlx_get_data_addr(game->south->mlx_img,
			&game->south->bpp, &game->south->line_len, &game->south->endian);
	game->east->addr = mlx_get_data_addr(game->east->mlx_img,
			&game->east->bpp, &game->east->line_len, &game->east->endian);
	game->west->addr = mlx_get_data_addr(game->west->mlx_img,
			&game->west->bpp, &game->west->line_len, &game->west->endian);
}

void	init_frame(t_game *game)
{
	game->frame = malloc(sizeof(t_img));
	game->frame->mlx_img = mlx_new_image(game->mlx, WINDOWWIDTH, WINDOWHEIGHT);
	game->frame->addr = mlx_get_data_addr(game->frame->mlx_img,
			&game->frame->bpp, &game->frame->line_len, &game->frame->endian);
}
