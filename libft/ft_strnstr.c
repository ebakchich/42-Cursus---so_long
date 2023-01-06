/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:21:06 by ebakchic          #+#    #+#             */
/*   Updated: 2021/11/28 15:07:03 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlen;

	if (*needle == '\0')
		return ((char *)haystack);
	needlen = ft_strlen(needle);
	while (*haystack != '\0' && len >= needlen)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, needlen) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
