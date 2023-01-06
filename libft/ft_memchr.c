/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:42:25 by ebakchic          #+#    #+#             */
/*   Updated: 2021/11/27 22:48:50 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s2;
	char	ca;
	size_t	i;

	s2 = (char *)s;
	ca = (char)c;
	i = 0;
	while (i < n)
	{
		if (s2[i] == ca)
			return (s2 + i);
		i++;
	}
	return (NULL);
}
