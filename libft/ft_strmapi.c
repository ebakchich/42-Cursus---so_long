/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:00:43 by ebakchic          #+#    #+#             */
/*   Updated: 2021/11/29 21:03:28 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*store;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[j])
		j++;
	store = malloc((j + 1) * sizeof(char));
	if (!store)
		return (NULL);
	while (s[i])
	{
		store[i] = f(i, s[i]);
		i++;
	}
	store[i] = '\0';
	return (store);
}
