/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_mnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:09:15 by lrosch            #+#    #+#             */
/*   Updated: 2022/05/27 14:29:22 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_mnl(const char *str)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_strlen_mnl(str);
	i = 0;
	ptr = (char *) ft_calloc(len + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
