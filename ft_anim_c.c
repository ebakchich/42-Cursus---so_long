/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:36:45 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/08 23:12:06 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    ft_anim_c(k_list *s)
{
    int	wid;
	int	hei;

    if (s->an == 500)
    {
        s->c = mlx_xpm_file_to_image(s->mx, "./img/c1.xpm", &wid, &hei);
        if (!s->c)
            ft_error("Error\n");
        ft_fill_mp(s, s->mp, 0, 0);
    }
    if (s->an == 1000)
    {
        s->c = mlx_xpm_file_to_image(s->mx, "./img/c2.xpm", &wid, &hei);
        if (!s->c)
            ft_error("Error\n");
        ft_fill_mp(s, s->mp, 0, 0);
    }
    if (s->an == 1500)
    {
        s->c = mlx_xpm_file_to_image(s->mx, "./img/c3.xpm", &wid, &hei);
        if (!s->c)
            ft_error("Error\n");
        ft_fill_mp(s, s->mp, 0, 0);
    }
    if (s->an == 2000)
    {
        s->c = mlx_xpm_file_to_image(s->mx, "./img/c4.xpm", &wid, &hei);
        if (!s->c)
            ft_error("Error\n");
        ft_fill_mp(s, s->mp, 0, 0);
    }
    if (s->an == 2500)
    {
        s->c = mlx_xpm_file_to_image(s->mx, "./img/c5.xpm", &wid, &hei);
        if (!s->c)
            ft_error("Error\n");
        ft_fill_mp(s, s->mp, 0, 0);
    }
    if (s->an == 3000)
    {
        s->c = mlx_xpm_file_to_image(s->mx, "./img/c6.xpm", &wid, &hei);
        if (!s->c)
            ft_error("Error\n");
        ft_fill_mp(s, s->mp, 0, 0);
        s->an = 0;
    }
    s->an++;
    return (0);
}