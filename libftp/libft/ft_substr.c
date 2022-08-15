/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:13:08 by lrosch            #+#    #+#             */
/*   Updated: 2022/06/28 17:27:51 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;

	i = 0;
	if (len == 0)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dest = malloc(1);
		*dest = '\0';
		return (dest);
	}
	dest = malloc(len + 1);
	if (dest == 0)
		return (0);
	while (i < start)
		i++;
	ft_strlcpy(dest, (s + i), len + 1);
	return (dest);
}
