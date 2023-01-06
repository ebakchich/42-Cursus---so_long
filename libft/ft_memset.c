/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:16:04 by ebakchic          #+#    #+#             */
/*   Updated: 2021/12/01 13:48:05 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	a;
	unsigned char	*str;
	size_t			i;

	a = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		str[i] = a;
		i++;
	}
	return (str);
}
