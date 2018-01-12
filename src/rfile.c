/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rfile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:30:58 by avishnev          #+#    #+#             */
/*   Updated: 2017/12/05 13:42:02 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

/*
** check count of connectoin tetr
*/

static int	check_congt(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				j++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				j++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				j++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				j++;
		}
		i++;
	}
	if (j == 6 || j == 8)
		return (j);
	return (0);
}

/*
**check conunts of charact for valid format
*/

static int	check_cnt(char *str, int cnt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 20 && str[i])
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++j > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (str[20] != '\n' && cnt == 21)
		return (4);
	if (!check_congt(str))
		return (5);
	return (0);
}

t_tetr		*get_piece(char *str, char value)
{
	t_point		*mi;
	t_point		*max;
	char		**pos;
	int			i;
	t_tetr		*tetr;

	mi = point_new(3, 3);
	max = point_new(0, 0);
	min_max(str, mi, max);
	pos = ft_memalloc(sizeof(char *) * (max->y - mi->y + 1));
	i = 0;
	while (i < max->y - mi->y + 1)
	{
		pos[i] = ft_strnew(max->x - mi->x + 1);
		ft_strncpy(pos[i], str + (mi->x) + (i + mi->y) * 5, max->x - mi->x + 1);
		i++;
	}
	tetr = tetr_new(pos, max->x - mi->x + 1, max->y - mi->y + 1, value);
	ft_memdel((void **)&mi);
	ft_memdel((void **)&max);
	return (tetr);
}

t_list		*rtetr(int fd)
{
	char	chr;
	char	*buff;
	t_list	*list;
	t_tetr	*t;
	int		cnt;

	buff = ft_strnew(21);
	chr = 'A';
	list = NULL;
	while ((cnt = read(fd, buff, 21)) >= 20)
	{
		if (check_cnt(buff, cnt) != 0 || (t = get_piece(buff, chr++)) == NULL)
		{
			ft_memdel((void **)&buff);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(t, sizeof(t_tetr)));
		ft_memdel((void **)&t);
	}
	ft_memdel((void **)&buff);
	if (cnt != 0)
		return (free_list(list));
	lstrev(&list);
	return (list);
}
