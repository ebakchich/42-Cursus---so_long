/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:22:18 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/12 22:38:51 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_chr_p(t_list *l, char **mp)
{
	int	i;
	int	j;

	i = 0;
	while (mp[i] != NULL)
	{
		j = 0;
		while (mp[i][j] != '\0')
		{
			if (mp[i][j] == 'P')
			{
				l->px = j;
				l->py = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_cp_map(t_list *l, char **mp)
{
	int		i;
	char	**p;

	i = 0;
	while (mp[i] != NULL)
		i++;
	l->cmp = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (mp[i] != NULL)
	{
		l->cmp[i] = ft_strdup(mp[i]);
		i++;
	}
	l->cmp[i] = NULL;
}

int	ft_can_move(t_list *l, int y, int x, int i)
{
	if (i == 0)
	{
		if (l->cmp[y][x] == '1' || l->cmp[y][x] == 'E')
			return (0);
		if (l->cmp[y][x] == 'C')
		{
			l->cmp[y][x] = '0';
			l->nc--;
		}
	}
	else
	{
		if (l->cmp[y][x] == '1')
			return (0);
		if (l->cmp[y][x] == 'E')
		{
			l->cmp[y][x] = '0';
			l->ex--;
		}
	}
	return (1);
}

void	ft_chr_path(t_list *l, int y, int x, int i)
{
	if (y > l->num_lines || x > l->line_lenth)
		return ;
	if (y < 0 || x < 0)
		return ;
	if (l->nc == 0)
		return ;
	l->cmp[y][x] = '1';
	if (ft_can_move(l, y, x + 1, i))
		ft_chr_path(l, y, x + 1, i);
	if (ft_can_move(l, y - 1, x, i))
		ft_chr_path(l, y - 1, x, i);
	if (ft_can_move(l, y, x - 1, i))
		ft_chr_path(l, y, x - 1, i);
	if (ft_can_move(l, y + 1, x, i))
		ft_chr_path(l, y + 1, x, i);
}

void	ft_check_path(char **mp, int k)
{
	t_list	*l;
	int		i;

	l = malloc(sizeof(t_list));
	l->nc = ft_check_content('C', mp);
	l->ex = 1;
	ft_chr_p(l, mp);
	ft_cp_map(l, mp);
	l->line_lenth = ft_strlen(mp[0]);
	i = 0;
	while (mp[i] != NULL)
		i++;
	l->num_lines = i;
	ft_chr_path(l, l->py, l->px, k);
	if ((k == 1 && l->ex == 0) || (k == 0 && l->nc == 0))
	{
		ft_free(l);
		return ;
	}
	ft_free(l);
	ft_error("Error\ninvalid path");
}
