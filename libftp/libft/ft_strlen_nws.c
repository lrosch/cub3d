/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_nws.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:28:47 by lrosch            #+#    #+#             */
/*   Updated: 2022/06/30 16:58:25 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_nws(const char *s)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != '\n' && s[i] != '\t')
			j++;
		i++;
	}
	return (j);
}
