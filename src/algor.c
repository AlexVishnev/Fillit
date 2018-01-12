/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:43:49 by avishnev          #+#    #+#             */
/*   Updated: 2017/12/05 14:38:46 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

int			ft_sqrt(int n)
{
	int i;

	i = 2;
	while (i * i < n)
		i++;
	return (i);
}

int			solve_fill(t_fill *fill, t_list *list)
{
	int		y;
	int		x;
	t_tetr	*t;

	if (list == NULL)
		return (1);
	y = 0;
	t = (t_tetr *)(list->content);
	while (y < fill->size - t->heigth + 1)
	{
		x = 0;
		while (x < fill->size - t->width + 1)
		{
			if (place(t, fill, x, y))
			{
				if (solve_fill(fill, list->next))
					return (1);
				else
					set_piece(t, fill, point_new(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

int			place(t_tetr *t, t_fill *fill, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < t->width)
	{
		j = 0;
		while (j < t->heigth)
		{
			if (t->pos[j][i] == '#' && fill->arr[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	set_piece(t, fill, point_new(x, y), t->var);
	return (1);
}

t_fill		*solve(t_list *list)
{
	t_fill	*fill;
	int		size;

	size = ft_sqrt(ft_lstcnt(list) * 4);
	fill = newfill(size);
	while (!solve_fill(fill, list))
	{
		size++;
		free_fill(fill);
		fill = newfill(size);
	}
	return (fill);
}
