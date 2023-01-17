/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:13:55 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/17 18:13:53 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_comp(int j, char *s, char c)
{
	int	l;
	int	i;

	l = ft_strlen(s) - 1;
	while (l >= 0 && s[l] == '\n')
	{
		s[l] = '\0';
		l--;
	}
	l = 0;
	i = 0;
	while (s[l])
	{
		if (s[l] == '\n')
			i++;
		l++;
	}
	if (j > i)
		return (0);
	return (1);
}

static int	count_words(char *s, char c)
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
	if (ft_comp(count, s, c))
		return (-1);
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

static char	**ft_allocate(char *s, char c, char **arr, int words)
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

char	**ft_split(char *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	if (words == -1)
		return (NULL);
	arr = malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = ft_allocate(s, c, arr, words);
	if (!arr)
		return (NULL);
	arr[words] = NULL;
	return (arr);
}
