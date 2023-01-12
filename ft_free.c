/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:58:15 by ebakchic          #+#    #+#             */
/*   Updated: 2023/01/12 17:59:07 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_list *l)
{
	int	i;

	i = 0;
	while (l->cmp[i])
	{
		free(l->cmp[i]);
		i++;
	}
	free(l->cmp);
	free(l);
}
