/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmanipul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:25:25 by avishnev          #+#    #+#             */
/*   Updated: 2017/12/05 14:26:13 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

void		lstrev(t_list **alst)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

size_t		ft_lstcnt(t_list *list)
{
	size_t	i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

t_list		*free_list(t_list *list)
{
	t_tetr	*tetr;
	t_list	*next;

	while (list)
	{
		tetr = (t_tetr *)list->content;
		next = list->next;
		tetr_free(tetr);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}
