/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:43:48 by hskowron          #+#    #+#             */
/*   Updated: 2022/06/28 17:16:39 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_no(char *buf, t_game *game)
{
	int	x;

	x = 0;
	while (buf[x] == ' ')
		x++;
	if (game->map_info->north == NULL)
	{
		ft_check_xpm(game, &buf[x]);
		game->map_info->north = ft_strdup_mnl(&buf[x]);
	}
	else
		err_exit("Invalid input", game);
	game->map_info->collected++;
}

void	get_so(char *buf, t_game *game)
{
	int	x;

	x = 0;
	while (buf[x] == ' ')
		x++;
	if (game->map_info->south == NULL)
	{
		ft_check_xpm(game, &buf[x]);
		game->map_info->south = ft_strdup_mnl(&buf[x]);
	}
	else
		err_exit("Invalid input", game);
	game->map_info->collected++;
}

void	get_we(char *buf, t_game *game)
{
	int	x;

	x = 0;
	while (buf[x] == ' ')
		x++;
	if (game->map_info->west == NULL)
	{
		ft_check_xpm(game, &buf[x]);
		game->map_info->west = ft_strdup_mnl(&buf[x]);
	}
	else
		err_exit("Invalid input", game);
	game->map_info->collected++;
}

void	get_ea(char *buf, t_game *game)
{
	int	x;

	x = 0;
	while (buf[x] == ' ')
		x++;
	if (game->map_info->east == NULL)
	{
		ft_check_xpm(game, &buf[x]);
		game->map_info->east = ft_strdup_mnl(&buf[x]);
	}
	else
		err_exit("Invalid input", game);
	game->map_info->collected++;
}
