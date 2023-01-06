/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:44:56 by ebakchic          #+#    #+#             */
/*   Updated: 2021/11/23 20:47:17 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = ft_calloc(lens1 + lens2 + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, lens1);
	ft_memmove(str + lens1, s2, lens2);
	str[lens1 + lens2 + 1] = '\0';
	return (str);
}
