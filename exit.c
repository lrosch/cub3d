/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:25:38 by lrosch            #+#    #+#             */
/*   Updated: 2022/06/30 16:28:04 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	event_esc(t_game *game)
{
	exit_game(game);
}

int	exit_game(t_game *game)
{
	free_all(game);
	exit(0);
}

void	err_exit(char *msg, t_game *game)
{
	printf("%s\n", msg);
	free_game(game);
	exit(EXIT_FAILURE);
}
