/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_nws.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:09:15 by lrosch            #+#    #+#             */
/*   Updated: 2022/06/30 16:49:02 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_nws(const char *str)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_strlen_nws(str);
	i = 0;
	ptr = (char *) ft_calloc(len + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		if (str[i] != '\t')
			ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
