/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_gm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:19:33 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/06 23:16:13 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_img(k_list *s)
{
    int	wid;
	int	hei;

    s->p = mlx_xpm_file_to_image(s->mx, "./img/p.xpm", &wid, &hei);
	if (!s->p)
		ft_error("Error\n");
	s->e = mlx_xpm_file_to_image(s->mx, "./img/e.xpm", &wid, &hei);
	if (!s->e)
		ft_error("Error\n");
	s->c = mlx_xpm_file_to_image(s->mx, "./img/c.xpm", &wid, &hei);
	if (!s->c)
		ft_error("Error\n");
	s->s = mlx_xpm_file_to_image(s->mx, "./img/s.xpm", &wid, &hei);
	if (!s->s)
		ft_error("Error\n");
	s->w = mlx_xpm_file_to_image(s->mx, "./img/w.xpm", &wid, &hei);
	if (!s->w)
		ft_error("Error\n");
}

void    ft_fill_mp(k_list *s, char **mp, int i, int j)
{
    while (mp[i] != NULL)
    {
        j = 0;
        while (mp[i][j] != '\0')
        {
            if (mp[i][j] == '1')
		        mlx_put_image_to_window(s->mx, s->wn, s->w, j * 64, i * 64);
            if (ft_strchr("0CEP", mp[i][j]) != NULL)
		        mlx_put_image_to_window(s->mx, s->wn, s->s, j * 64, i * 64);
            if (mp[i][j] == 'P')
		        mlx_put_image_to_window(s->mx, s->wn, s->p, j * 64, i * 64);
            if (mp[i][j] == 'C')
		        mlx_put_image_to_window(s->mx, s->wn, s->c, j * 64, i * 64);
            if (mp[i][j] == 'E')
                mlx_put_image_to_window(s->mx, s->wn, s->e, j * 64, i * 64);
            j++;
        }
        i++;
    }
}

void    ft_creat_gm(char **mp)
{
    k_list  s;

    s.nn = 0;
    while (mp[s.nn])
        s.nn++;
    s.ln = ft_strlen(mp[0]);
    s.mx = mlx_init();
    s.wn = mlx_new_window(s.mx, s.ln * 64, s.nn * 64, "so_long");
    ft_img(&s);
    ft_fill_mp(&s, mp, 0, 0);
    mlx_hook(s.wn, 17, 0L, ft_action, &s);
    mlx_key_hook(s.wn, ft_manage_key, &s);
    mlx_loop(s.mx);
}
