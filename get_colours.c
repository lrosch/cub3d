/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colours.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:50:56 by lrosch            #+#    #+#             */
/*   Updated: 2022/06/28 17:49:09 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_colours(char *str, t_game *game)
{
	int		i;
	int		j;
	int		k;
	char	**colours;

	i = 0;
	k = 0;
	colours = malloc(sizeof(char *) * 4);
	colours[3] = NULL;
	while (str[i] && k < 3)
	{
		j = 0;
		while (str[i] == ',' || str[i] == ' ')
			i++;
		while (str[i + j] >= '0' && str[i + j] <= '9')
			j++;
		colours[k] = ft_substr(str, i, j);
		i = i + j;
		k++;
	}
	check_col_array(colours, game, k);
	j = create_rgb(ft_atoi(colours[0]), ft_atoi(colours[1]),
			ft_atoi(colours[2]));
	free2d(colours);
	return (j);
}

void	check_col_array(char **colours, t_game *game, int k)
{
	int	x;

	x = 0;
	if (k < 3)
		err_exit("Invalid input", game);
	while (x < 3)
	{
		if (colours[x] == NULL)
		{
			free2d(colours);
			err_exit("Invalid input", game);
		}
		x++;
	}
}
