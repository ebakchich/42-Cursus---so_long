/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:44:56 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/12 17:12:47 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(int r, char *s1, char *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	if (r == 0)
		lens1 = 0;
	lens2 = ft_strlen(s2);
	str = malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (r != 0)
		ft_memmove(str, s1, lens1);
	ft_memmove(str + lens1, s2, lens2);
	str[lens1 + lens2] = '\0';
	if (r != 0)
		free(s1);
	return (str);
}
