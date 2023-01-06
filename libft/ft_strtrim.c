/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:52:10 by ebakchic          #+#    #+#             */
/*   Updated: 2021/12/01 14:47:35 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char const *set, char a)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	lens1;

	if (!s1)
		return (NULL);
	if (!set)
		return (NULL);
	str = (char *)s1;
	lens1 = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_check(set, s1[i]))
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	if ((i + 1) == lens1)
		return (NULL);
	while (lens1 > 0 && ft_check(set, s1[lens1 - 1]))
		lens1--;
	str = ft_calloc(lens1 - i + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memmove(str, s1 + i, lens1 - i);
	str[lens1 - i + 1] = '\0';
	return (str);
}
