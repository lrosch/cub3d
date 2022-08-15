/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:01:26 by lrosch            #+#    #+#             */
/*   Updated: 2022/07/04 16:56:38 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "minilibx/mlx.h"
# include "libftp/libftp.h"

# define PI M_PI
# define FOV 60
# define MUL 4
# define PLANEWIDTH 320
# define PLANEHEIGHT 200
# define WINDOWWIDTH 1280
# define WINDOWHEIGHT 800

typedef struct s_or
{
	double	x;
	double	y;
}				t_or;

typedef struct s_map_info
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceiling;
	int		collected;
}				t_map_info;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_game {
	int			map_start;
	char		*map_path;
	t_map_info	*map_info;
	char		**map;
	int			img_pos;

	t_img		*north;
	t_img		*south;
	t_img		*west;
	t_img		*east;
	t_img		*frame;

	void		*win;
	void		*mlx;

	int			size;
	double		py;
	double		px;
	t_or		*or;
	int			degree;

	int			p_dis;
	int			last;
	double		j;
	double		deg_mul;
	double		temp_deg;
	double		temp_x;
	double		temp_y;
}				t_game;

/* R,G,B functions */
int		create_rgb(int r, int g, int b);
int		get_r(int rgb);
int		get_g(int rgb);
int		get_b(int rgb);

// /* utils */
int		count_lines(char *path);

int		get_colours(char *str, t_game *game);

/*	free functions	*/
void	free2d(char **str);

/*	wip stuff	*/
void	wip_stuff(t_game *game, char **argv);

/*	init	*/
void	init_map_info(t_map_info *map_info);
void	init_game(t_game *game, char **argv);

/*	parsing	*/
void	parsing(int fd, t_game *game);
void	parsing_on(int fd, t_game *game, char *buf);
void	copy_map(char *buf, int fd, t_game *game);

/*	get attributes	*/
void	check_ele(char *buf, t_game *game);
void	get_f(char *buf, t_game *game);
void	get_c(char *buf, t_game *game);
void	get_no(char *buf, t_game *game);
void	get_so(char *buf, t_game *game);
void	get_we(char *buf, t_game *game);
void	get_ea(char *buf, t_game *game);

/*	map validation	*/
void	map_validation(t_game *game);
void	check_element(t_game *game, int y, int x);
int		check_above_row(char **map, int y, int x);
int		check_below_row(char **map, int y, int x);

/*	error	*/
void	err_exit(char *msg, t_game *game);

void	cast_rays(t_game *game);
void	event_a(t_game *game);
void	event_d(t_game *game);
void	event_s(t_game *game);
void	event_w(t_game *game);
void	rotate_we(t_game *game);
void	rotate_ea(t_game *game);
void	change_orientation(t_game *game);
void	cast_rays_positive(t_game *game);
void	cast_rays_negative(t_game *game);
void	draw_wall(t_game *game, int wall_y, int wall_x, int column);
void	draw_background(t_game *game);
void	img_pix_put(t_img *img, int x, int y, int color);
void	draw_x_wall(t_game *game, int height, int offset);
void	set_walls(t_game *game);
void	tex_img_put_n(t_game *game, int height, int offset);
void	tex_img_put_w(t_game *game, int height, int offset);
void	tex_img_put_e(t_game *game, int height, int offset);
void	tex_img_put_s(t_game *game, int height, int offset);
void	init_frame(t_game *game);
void	colour_c_f(t_game *game, int start, int height);
int		create_rgb_2(uint8_t red, uint8_t green, uint8_t blue);
void	get_player_pos(t_game *game);
int		get_orientation(t_game *game, char c);
void	scale_big_texture(t_img *tex, int height, int offset, t_game *game);
void	color_tmp(int height, t_img *tmp, t_img *tex, int offset);
void	cut_tmp(int start, t_game *game, t_img *tmp);
void	ft_check_cub(char **argv);
void	rotate_reverse(t_game *game);
void	cut_tmp_mlx(t_game *game, int start, int i);
void	scale_texture(t_img *tex, int height, int offset, t_game *game);
int		examine_ray(int wall_x, int wall_y, t_game *game, double temp_deg);
int		case_distinction(t_game *game, double temp_deg, char *arr);
int		further_examination(int wall_x, int wall_y, t_game *game, char *arr);
void	event_esc(t_game *game);
int		exit_game(t_game *game);
void	free_images(t_game *game);
void	free_all(t_game *game);
void	free_map_info(t_game *game);
void	ft_check_xpm(t_game *game, char *str);
void	check_col_array(char **colours, t_game *game, int k);
void	free_game(t_game *game);
void	check_xpm(t_game *game);

#endif
