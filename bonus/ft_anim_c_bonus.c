/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim_c_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:36:45 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/13 16:08:41 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_anim_c(t_listt *s)
{
	t_lst	a;

	if (s->an == 500)
		s->c = mlx_xpm_file_to_image(s->mx, "./img/c1.xpm", &a.wid, &a.hei);
	if (s->an == 1000)
		s->c = mlx_xpm_file_to_image(s->mx, "./img/c2.xpm", &a.wid, &a.hei);
	if (s->an == 1500)
		s->c = mlx_xpm_file_to_image(s->mx, "./img/c3.xpm", &a.wid, &a.hei);
	if (s->an == 2000)
		s->c = mlx_xpm_file_to_image(s->mx, "./img/c4.xpm", &a.wid, &a.hei);
	if (s->an == 2500)
		s->c = mlx_xpm_file_to_image(s->mx, "./img/c5.xpm", &a.wid, &a.hei);
	if (s->an == 3000)
	{
		s->c = mlx_xpm_file_to_image(s->mx, "./img/c6.xpm", &a.wid, &a.hei);
		s->an = 0;
	}
	if (s->an == 3000 || s->an == 2500
		|| s->an == 2000 || s->an == 1500
		|| s->an == 1000 || s->an == 500)
		ft_fill_mp(s, s->mp, 0, 0);
	if (!s->c)
		ft_error("Error\n");
	s->an++;
	return (0);
}
