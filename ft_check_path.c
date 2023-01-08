/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:22:18 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/09 00:06:15 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_chr_p(t_list *l, char **mp)
{
    int i;
    int j;

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

int    can_be_path(t_list *l, int x, int y, int i)
{
	if (y <= 0 || x <= 0)
		return (-1);
	if (x > l->line_lenth || y > l->num_lines)
		return (-1);
    if (i == 0)
    {
        if (l->cmp[y][x] == '1' || l->cmp[y][x] == 'E' || l->cmp[y][x] == 'N')
            return (-1);
        if (l->cmp[y][x] == 'C')
        {
            l->cmp[y][x] = '0';
            l->nc--;
        }
    }
    else
    {
        if (l->cmp[y][x] == '1' || l->cmp[y][x] == 'N')
            return (-1);
        if (l->cmp[y][x] == 'E')
        {
            l->cmp[y][x] = '0';
            l->ex--;
        }
    }
	return (1);
}

void    ft_chr_path(t_list *l, int x, int y, int i)
{
    if (l->nc == 0)
        return ;
    l->cmp[y][x] = '1';
    if (can_be_path(l, x + 1, y, i) != -1)
		ft_chr_path(l, x + 1, y, i);
	if (can_be_path(l, x, y - 1, i) != -1)
		ft_chr_path(l, x, y - 1, i);
	if (can_be_path(l, x - 1, y, i) != -1)
		ft_chr_path(l, x - 1, y, i);
	if (can_be_path(l, x, y + 1, i) != -1)
		ft_chr_path(l, x, y + 1, i);
}

void    ft_cp_map(t_list *l, char **mp)
{
    int i;
    char    **p;

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

void    ft_check_path(char **mp)
{
    t_list  *l;
    int i;

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
    ft_chr_path(l, l->px, l->py, 0);
    //ft_chr_path(l, l->px, l->py, 1);
    if (l->nc == 0)
        return ;
	else
        ft_error("Error\ninvalid path");
}
