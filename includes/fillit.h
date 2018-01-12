/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <avishnev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:55:00 by avishnev          #+#    #+#             */
/*   Updated: 2017/12/05 12:00:30 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_fill
{
	int				size;
	char			**arr;
}				t_fill;

typedef struct	s_point
{
	int				x;
	int				y;
}				t_point;

typedef struct	s_tetr
{
	char			**pos;
	int				width;
	int				heigth;
	char			var;
}				t_tetr;

size_t			ft_lstcnt(t_list *list);
void			printfill(t_fill *fill);
void			set_piece(t_tetr *tetr, t_fill *fill, t_point *point, char c);
void			min_max(char *str, t_point *min, t_point *max);
void			tetr_free(t_tetr *tetr);
void			free_fill(t_fill *fill);
void			ft_lstadd(t_list **alst, t_list *new);
void			lstrev(t_list **alst);
int				place(t_tetr *t, t_fill *fill, int x, int y);
int				solve_fill(t_fill *fill, t_list *list);
int				ft_sqrt(int n);
t_fill			*newfill(int size);
t_fill			*solve(t_list *list);
t_point			*point_new(int x, int y);
t_tetr			*tetr_new(char **pos, int width, int heigth, char var);
t_tetr			*get_piece(char *str, char value);
t_list			*ft_lstnew(void const *data, size_t data_size);
t_list			*free_list(t_list *list);
t_list			*rtetr(int fd);

#endif
