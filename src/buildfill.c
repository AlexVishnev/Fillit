/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <avishnev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:23:00 by avishnev          #+#    #+#             */
/*   Updated: 2017/11/20 16:23:00 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

void	printfill(t_fill *fill)
{
	int	i;

	i = 0;
	while (i < fill->size)
	{
		ft_putstr(fill->arr[i]);
		ft_putchar('\n');
		i++;
	}
}

/*
** alloc mem for fill. gives params to struct "fill"
*/

t_fill	*newfill(int size)
{
	int		i;
	int		j;
	t_fill	*fill;

	fill = (t_fill *)ft_memalloc(sizeof(t_fill));
	fill->size = size;
	fill->arr = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		fill->arr[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			fill->arr[i][j] = '.';
			j++;
		}
		i++;
	}
	return (fill);
}

/*
**	set figure on fill at pos whith spec chr;
*/

void	set_piece(t_tetr *tetr, t_fill *fill, t_point *point, char c)
{
	int i;
	int j;

	i = 0;
	while (i < tetr->width)
	{
		j = 0;
		while (j < tetr->heigth)
		{
			if (tetr->pos[j][i] == '#')
				fill->arr[point->y + j][point->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}
