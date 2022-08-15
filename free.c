/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:10:17 by lrosch            #+#    #+#             */
/*   Updated: 2022/06/28 18:17:11 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free2d(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i])
				free(str[i]);
			i++;
		}
		if (str)
			free(str);
	}
}

void	free_all(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free2d(game->map);
	free_images(game);
	free_map_info(game);
	free(game->or);
}

void	free_map_info(t_game *game)
{
	if (game->map_info->east)
		free(game->map_info->east);
	if (game->map_info->south)
		free(game->map_info->south);
	if (game->map_info->west)
		free(game->map_info->west);
	if (game->map_info->north)
		free(game->map_info->north);
	if (game->map_info)
		free(game->map_info);
	if (game->map_path)
		free(game->map_path);
}

void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->north->mlx_img);
	mlx_destroy_image(game->mlx, game->south->mlx_img);
	mlx_destroy_image(game->mlx, game->west->mlx_img);
	mlx_destroy_image(game->mlx, game->east->mlx_img);
	free(game->east);
	free(game->south);
	free(game->north);
	free(game->west);
}

void	free_game(t_game *game)
{
	free2d(game->map);
	free(game->or);
	free_map_info(game);
	free(game->east);
	free(game->south);
	free(game->north);
	free(game->west);
	mlx_destroy_image(game->mlx, game->frame->mlx_img);
	free(game->frame);
}
