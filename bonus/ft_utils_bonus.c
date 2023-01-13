/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:04:22 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/13 16:26:41 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_mov(int i, t_listt *s)
{
	char	*c;

	c = ft_itoa(s->nm);
	if (i == 0)
	{
		write(1, "move = ", 7);
		ft_putstr(c);
		write(1, "\n", 1);
	}
	else
		mlx_string_put(s->mx, s->wn, 25, 25, 0x07FF09, c);
	free(c);
}

void	ft_move_action(int i, int x, int y, t_listt *s)
{
	if (s->mp[y][x] == 'C')
		s->nc--;
	if (i == 0)
		s->mp[y + 1][x] = '0';
	else if (i == 1)
		s->mp[y - 1][x] = '0';
	else if (i == 2)
		s->mp[y][x - 1] = '0';
	else if (i == 3)
		s->mp[y][x + 1] = '0';
	s->mp[y][x] = 'P';
	s->x = x;
	s->y = y;
	s->nm++;
	ft_fill_mp(s, s->mp, 0, 0);
	ft_print_mov(0, s);
}

void	ft_move(int i, int x, int y, t_listt *s)
{
	if (s->mp[y][x] == '0' || s->mp[y][x] == 'C')
		ft_move_action(i, x, y, s);
	else if (s->mp[y][x] == 'E' && s->nc == 0)
	{
		s->nm++;
		ft_print_mov(0, s);
		write(1, "Winner Winner Chicken Dinner\n", 29);
		exit(EXIT_SUCCESS);
	}
	else if (s->mp[y][x] == 'N')
	{
		s->nm++;
		ft_print_mov(0, s);
		write(1, "Better Luck Next Time", 22);
		exit(EXIT_FAILURE);
	}
}

int	ft_action(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_manage_key(int k, t_listt *s)
{
	if (k == 53)
		exit(EXIT_SUCCESS);
	if (k == 13)
		ft_move(0, s->x, s->y - 1, s);
	if (k == 1)
		ft_move(1, s->x, s->y + 1, s);
	if (k == 2)
		ft_move(2, s->x + 1, s->y, s);
	if (k == 0)
		ft_move(3, s->x - 1, s->y, s);
	return (0);
}
