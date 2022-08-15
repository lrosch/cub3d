/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:01:55 by lrosch            #+#    #+#             */
/*   Updated: 2022/06/30 17:02:40 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	button_event(int keycode, t_game *game)
{
	if (keycode == 0)
		event_a(game);
	else if (keycode == 2)
		event_d(game);
	else if (keycode == 1)
		event_s(game);
	else if (keycode == 13)
		event_w(game);
	else if (keycode == 124)
		rotate_ea(game);
	else if (keycode == 123)
		rotate_we(game);
	else if (keycode == 53)
		event_esc(game);
	else
		return (0);
	change_orientation(game);
	mlx_clear_window(game->mlx, game->win);
	cast_rays(game);
	return (0);
}

void	init_game(t_game *game, char **argv)
{
	game->mlx = mlx_init();
	game->map_info = malloc(sizeof(t_map_info));
	game->or = malloc(sizeof(t_or));
	game->north = malloc(sizeof(t_img));
	game->south = malloc(sizeof(t_img));
	game->east = malloc(sizeof(t_img));
	game->west = malloc(sizeof(t_img));
	game->img_pos = 0;
	game->deg_mul = (WINDOWWIDTH / 2) / 30;
	init_frame(game);
	game->size = 64;
	game->map = NULL;
	game->p_dis = (PLANEWIDTH / 2) / tan(FOV / 2 * PI / 180);
	game->map_path = ft_strdup(argv[1]);
	game->map_start = 1;
	if (!game->map_info)
		exit(EXIT_FAILURE);
	init_map_info(game->map_info);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc != 2)
	{
		printf("Error\ninvalid input\n");
		exit(EXIT_FAILURE);
	}
	ft_check_cub(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\ninvalid map\n");
		exit(EXIT_FAILURE);
	}
	init_game(&game, argv);
	parsing(fd, &game);
	map_validation(&game);
	set_walls(&game);
	game.win = mlx_new_window(game.mlx, WINDOWWIDTH, WINDOWHEIGHT, "cub3d");
	cast_rays(&game);
	mlx_hook(game.win, 2, (1L << 0), button_event, &game);
	mlx_hook(game.win, 17, (1L << 17), exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
