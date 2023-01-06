/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:57:52 by ebakchic          #+#    #+#             */
/*   Updated: 2021/12/06 15:43:33 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cup;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s1);
	cup = (char *)malloc(sizeof(char) * (size + 1));
	if (cup == NULL)
		return (NULL);
	while (s1[i])
	{
		cup[i] = s1[i];
		i++;
	}
	cup[i] = '\0';
	return (cup);
}
