/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:24:25 by ebakchic          #+#    #+#             */
/*   Updated: 2021/12/06 15:47:37 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (len != 0)
		ft_memmove(str, s + start, len);
	str[len + 1] = '\0';
	return (str);
}
