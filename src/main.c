/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:42:19 by avishnev          #+#    #+#             */
/*   Updated: 2017/12/05 14:42:41 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

static int		ft_in_valid(char *a)
{
	char	*buff;
	int		cnt;
	int		fd;

	fd = open(a, O_RDONLY);
	buff = ft_strnew(21 * 26);
	cnt = read(fd, buff, 21 * 26);
	if ((ft_strlen(buff) + 1) % 21 != 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	ft_memdel((void **)&buff);
	close(fd);
	return (0);
}

int				main(int argc, char **argv)
{
	t_list	*list;
	t_fill	*fill;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if (ft_in_valid(argv[1]) != 0)
		return (1);
	if ((list = rtetr(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	fill = solve(list);
	printfill(fill);
	free_fill(fill);
	free_list(list);
	return (0);
}
