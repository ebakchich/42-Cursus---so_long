/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_gm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:19:33 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/17 15:07:17 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_chr_pp(t_listt *s)
{
	int	i;
	int	j;

	i = 0;
	while (s->mp[i] != NULL)
	{
		j = 0;
		while (s->mp[i][j] != '\0')
		{
			if (s->mp[i][j] == 'P')
			{
				s->x = j;
				s->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_cp_mapp(t_listt *s, char **mp)
{
	int		i;
	char	**p;

	i = 0;
	while (mp[i] != NULL)
		i++;
	s->mp = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (mp[i] != NULL)
	{
		s->mp[i] = ft_strdup(mp[i]);
		i++;
	}
	s->mp[i] = NULL;
}

void	ft_img(t_listt *s)
{
	int	wid;
	int	hei;

	s->p = mlx_xpm_file_to_image(s->mx, "./img/p.xpm", &wid, &hei);
	if (!s->p)
		ft_error("Error\nmlx_xpm_file_to_image return NULL");
	s->e = mlx_xpm_file_to_image(s->mx, "./img/e.xpm", &wid, &hei);
	if (!s->e)
		ft_error("Error\nmlx_xpm_file_to_image return NULL");
	s->c = mlx_xpm_file_to_image(s->mx, "./img/c1.xpm", &wid, &hei);
	if (!s->c)
		ft_error("Error\nmlx_xpm_file_to_image return NULL");
	s->s = mlx_xpm_file_to_image(s->mx, "./img/s.xpm", &wid, &hei);
	if (!s->s)
		ft_error("Error\nmlx_xpm_file_to_image return NULL");
	s->w = mlx_xpm_file_to_image(s->mx, "./img/w.xpm", &wid, &hei);
	if (!s->w)
		ft_error("Error\nmlx_xpm_file_to_image return NULL");
	s->n = mlx_xpm_file_to_image(s->mx, "./img/n.xpm", &wid, &hei);
	if (!s->n)
		ft_error("Error\nmlx_xpm_file_to_image return NULL");
}

void	ft_fill_mp(t_listt *s, char **mp, int i, int j)
{
	while (mp[i] != NULL)
	{
		j = 0;
		while (mp[i][j] != '\0')
		{
			if (ft_strchr("0CEPN1", mp[i][j]) != NULL)
				mlx_put_image_to_window(s->mx, s->wn, s->s, j * 64, i * 64);
			if (mp[i][j] == '1')
				mlx_put_image_to_window (s->mx, s->wn, s->w, j * 64, i * 64);
			if (mp[i][j] == 'P')
				mlx_put_image_to_window(s->mx, s->wn, s->p, j * 64, i * 64);
			if (mp[i][j] == 'C')
				mlx_put_image_to_window(s->mx, s->wn, s->c, j * 64, i * 64);
			if (mp[i][j] == 'E')
				mlx_put_image_to_window(s->mx, s->wn, s->e, j * 64, i * 64);
			if (mp[i][j] == 'N')
				mlx_put_image_to_window(s->mx, s->wn, s->n, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	ft_creat_gm(char **mp)
{
	t_listt	s;

	s.nn = 0;
	s.nm = 0;
	s.an = 0;
	ft_cp_mapp(&s, mp);
	ft_chr_pp(&s);
	s.nc = ft_check_content('C', mp);
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
