/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:23:29 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/05 20:47:14 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read(int fd, char *saver)
{
	char	*buff;
	int		rb;
	int		b;

	b = 1;
	buff = ft_calloc(b + 1, sizeof(char));
	if (!buff)
		return (NULL);
	rb = 1;
	while (rb != 0)
	{
		rb = read(fd, buff, b);
		if (rb == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rb] = '\0';
		saver = ft_strjoin(saver, buff);
	}
	free(buff);
	if (saver[0] == '\0')
		ft_error("Error\nMap empty");
	return (saver);
}

void	read_map(int fd)
{
	char	*saver;
	char	**mp;

	saver = (char *)malloc(sizeof(char));
	saver = ft_read(fd, saver);
	mp = ft_split(saver, '\n');
	ft_checkmap(mp);
}
