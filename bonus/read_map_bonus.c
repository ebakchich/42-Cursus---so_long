/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:23:29 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/17 18:36:29 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_read(int fd, char *saver)
{
	char	*buff;
	int		rb;
	int		r;

	r = 0;
	buff = ft_calloc(2, sizeof(char));
	if (!buff)
		return (NULL);
	rb = 1;
	while (rb != 0)
	{
		rb = read(fd, buff, 1);
		if (rb == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rb] = '\0';
		if (rb != 0)
			saver = ft_strjoin(r, saver, buff);
		r++;
	}
	free(buff);
	return (saver);
}

void	read_map(int fd)
{
	char	*saver;
	char	**mp;
	int		i;

	i = 0;
	saver = ft_read(fd, saver);
	if (saver[0] == '\0' && saver == NULL)
		ft_error("Error\nMap empty");
	mp = ft_split(saver, '\n');
	free(saver);
	if (mp == NULL)
		ft_error("Error\nMap not valid");
	ft_checkmap(mp);
	while (mp[i])
	{
		free(mp[i]);
		i++;
	}
	free(mp);
}
