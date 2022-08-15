/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:44:49 by lrosch            #+#    #+#             */
/*   Updated: 2022/06/16 18:45:34 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_rgb_2(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_r(int rgb)
{
	return ((rgb >> 16) & 0xFF);
}

int	get_g(int rgb)
{
	return ((rgb >> 8) & 0xFF);
}

int	get_b(int rgb)
{
	return (rgb & 0xFF);
}
