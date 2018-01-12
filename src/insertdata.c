/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:06:40 by avishnev          #+#    #+#             */
/*   Updated: 2017/12/05 14:38:51 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

void		min_max(char *str, t_point *min, t_point *max)
{
	int			i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

t_point		*point_new(int x, int y)
{
	t_point		*p;

	p = ft_memalloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	return (p);
}

t_tetr		*tetr_new(char **pos, int width, int heigth, char var)
{
	t_tetr		*tetr;

	tetr = ft_memalloc(sizeof(t_tetr));
	tetr->pos = pos;
	tetr->width = width;
	tetr->heigth = heigth;
	tetr->var = var;
	return (tetr);
}

void		tetr_free(t_tetr *tetr)
{
	int			y;

	y = 0;
	while (y < tetr->heigth)
	{
		ft_memdel((void **)(&(tetr[y])));
		y++;
	}
	ft_memdel((void **)(&(tetr->pos)));
	ft_memdel((void **)&tetr);
}

void		free_fill(t_fill *fill)
{
	int			i;

	i = 0;
	while (i < fill->size)
	{
		ft_memdel((void **)&(fill->arr[i]));
		i++;
	}
	ft_memdel((void **)&(fill->arr));
	ft_memdel((void **)&fill);
}
