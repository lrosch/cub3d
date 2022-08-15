/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:14:13 by lrosch            #+#    #+#             */
/*   Updated: 2022/06/28 16:37:35 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_lines(char *path)
{
	int		lines;
	char	*str;
	int		fd;

	lines = 0;
	fd = open(path, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free (str);
		lines++;
	}
	close(fd);
	return (lines);
}

void	ft_check_cub(char **argv)
{
	char	*check;

	check = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 4);
	if (ft_strncmp(check, ".cub", 4))
	{
		printf("Error\nno .cub extension\n");
		free(check);
		exit(EXIT_FAILURE);
	}
	free(check);
}

void	ft_check_xpm(t_game *game, char *str)
{
	char	*check;

	check = ft_substr(str, ft_strlen_mnl(str) - 4, 4);
	if (ft_strncmp(check, ".xpm", 4))
	{
		free(check);
		err_exit("Error\nno .xpm extension\n", game);
	}
	free(check);
}
