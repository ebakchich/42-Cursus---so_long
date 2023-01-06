/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:54:08 by ebakchic          #+#    #+#             */
/*   Updated: 2021/11/12 20:44:02 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	ca;
	int		i;

	str = (char *)s;
	ca = (char)c;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == ca)
			return (str + i);
		i--;
	}
	return (NULL);
}
