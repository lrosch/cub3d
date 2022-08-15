/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:55:04 by hskowron          #+#    #+#             */
/*   Updated: 2022/06/30 17:02:32 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map_info(t_map_info *map_info)
{
	map_info->north = NULL;
	map_info->east = NULL;
	map_info->west = NULL;
	map_info->south = NULL;
	map_info->floor = 0;
	map_info->ceiling = 0;
	map_info->collected = 0;
}

void	parsing(int fd, t_game *game)
{
	char	*buf;
	int		x;

	x = 0;
	buf = get_next_line(fd);
	while (buf && game->map_info->collected < 6)
	{
		if (buf[x] != '\0' || buf[x] != '\n')
		{
			while (buf[x] == ' ')
				x++;
			check_ele(&buf[x], game);
		}
		free(buf);
		buf = get_next_line(fd);
		x = 0;
		game->map_start++;
	}
	if (!buf && game->map_info->collected < 6)
		err_exit("Invalid input", game);
	parsing_on(fd, game, buf);
}

void	parsing_on(int fd, t_game *game, char *buf)
{
	int		x;

	x = 0;
	while (buf)
	{
		if (buf[0] != '\0' && buf[0] != '\n')
		{
			while (buf[x] == ' ')
				x++;
			if (buf[x])
			{
				copy_map(buf, fd, game);
				return ;
			}
		}
		free(buf);
		buf = get_next_line(fd);
		x = 0;
		game->map_start++;
	}
	err_exit("Invalid input", game);
}

void	check_ele(char *buf, t_game *game)
{
	if (ft_strncmp(buf, "NO ", 3) == 0)
		get_no(buf + 2, game);
	else if (ft_strncmp(buf, "SO ", 3) == 0)
		get_so(buf + 2, game);
	else if (ft_strncmp(buf, "WE ", 3) == 0)
		get_we(buf + 2, game);
	else if (ft_strncmp(buf, "EA ", 3) == 0)
		get_ea(buf + 2, game);
	else if (ft_strncmp(buf, "F ", 2) == 0)
		get_f(buf + 1, game);
	else if (ft_strncmp(buf, "C ", 2) == 0)
		get_c(buf + 1, game);
}

void	copy_map(char *buf, int fd, t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	game->map = malloc(sizeof(char *) * (2 + count_lines(game->map_path)
				- game->map_start));
	if (!game->map)
		err_exit("malloc error", game);
	while (buf)
	{
		if (buf[x] != '\0')
		{
			game->map[y] = ft_strdup_mnl(buf);
			y++;
		}
		game->map[y] = NULL;
		free(buf);
		buf = get_next_line(fd);
	}
	get_player_pos(game);
	close(fd);
}
