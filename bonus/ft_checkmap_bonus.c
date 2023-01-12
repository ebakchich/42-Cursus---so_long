/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:02:35 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/12 23:45:24 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_wall(int len, char **mp)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (j < len)
	{
		if (mp[0][j] != '1')
			ft_error("Error\nCheck wall");
		j++;
	}
	while (mp[i + 1] != NULL)
	{
		if (mp[i][0] != '1' || mp[i][len - 1] != '1')
			ft_error("Error\nCheck wall");
		i++;
	}
	j = 0;
	while (j < len)
	{
		if (mp[i][j] != '1')
			ft_error("Error\nCheck wall");
		j++;
	}
}

int	ft_check_content(int c, char **mp)
{
	int	i;
	int	j;
	int	nc;

	nc = 0;
	i = 0;
	while (mp[i] != NULL)
	{
		j = 0;
		while (mp[i][j] != '\0')
		{
			if (mp[i][j] == c)
				nc++;
			j++;
		}
		i++;
	}
	return (nc);
}

void	ft_check_components(char **mp)
{
	int	i;
	int	j;

	i = 0;
	while (mp[i] != NULL)
	{
		j = 0;
		while (mp[i][j] != '\0')
		{
			if (ft_strchr("01CEPN", mp[i][j]) == NULL)
				ft_error("Error\nCheck components");
			j++;
		}
		i++;
	}
}

void	ft_checkmap(char **mp)
{
	int	i;
	int	l;

	l = ft_strlen(mp[0]);
	i = 1;
	while (mp[i] != NULL)
	{
		if (l != ft_strlen(mp[i]))
			ft_error("Error\nThe map must be rectangular");
		i++;
	}
	if (i <= 2)
		ft_error("Error\nMap not valid");
	ft_check_components(mp);
	ft_check_wall(l, mp);
	if (ft_check_content('E', mp) != 1)
		ft_error("Error\nmap must contain 1 exit");
	if (ft_check_content('P', mp) != 1)
		ft_error("Error\nThe map must contain 1 starting position");
	if (ft_check_content('C', mp) == 0)
		ft_error("Error\nThe map must contain at least 1 collectible,");
	ft_check_path(mp, 0);
	ft_check_path(mp, 1);
	ft_creat_gm(mp);
}
