/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:13:55 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/05 20:56:31 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		count++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static char	**free_allocation(char **arr, int k)
{
	while (k >= 0)
	{
		free(arr[k]);
		k--;
	}
	free(arr);
	return (NULL);
}

static char	**ft_allocate(char const *s, char c, char **arr, int words)
{
	int	i;
	int	len;
	int	k;

	len = 0;
	k = 0;
	if (!s || !arr)
		return (NULL);
	while (s[len] && k < words)
	{
		while (s[len] && s[len] == c)
			len++;
		i = len;
		while (s[i] && s[i] != c)
			i++;
		arr[k] = malloc((i - len + 1) * sizeof(char));
		if (!arr[k])
			return (free_allocation(arr, k));
		ft_strlcpy(*(arr + k), s + len, i - len + 1);
		len = i;
		k++;
	}
	arr[words] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = ft_allocate(s, c, arr, words);
	if (!arr)
		return (NULL);
	arr[words] = 0;
	return (arr);
}
