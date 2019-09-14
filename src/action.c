/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:21:39 by tcase             #+#    #+#             */
/*   Updated: 2019/09/14 21:22:26 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		remove(void)
{
	t_list		*list;
	t_elem		*elem;
	size_t		len;

	list = g_msh->select->elem_list;
	if ((len = ft_strlen(g_msh->select->search_line)) > 0)
	{
		g_msh->select->search_line[len - 1] = 0;
		return ;
	}
	while (list)
	{
		elem = list->content;
		if (elem->current == 1)
		{
			if (list->next)
				(((t_elem*)list->next->content)->current = 1);
			else
				(((t_elem*)g_msh->select->elem_list->content)->current = 1);
			ft_lst_remove(&g_msh->select->elem_list, &list, &del_elem);
			return ;
		}
		list = list->next;
	}
}

static void		choose(void)
{
	t_list		*list;
	t_elem		*elem;

	list = g_msh->select->elem_list;
	if (g_msh->select->search_line[0])
		ft_bzero(g_msh->select->search_line, PATH_MAX);
	while (list)
	{
		elem = list->content;
		if (elem->current == 1)
		{
			elem->selected ^= 1;
			return ;
		}
		list = list->next;
	}
}

void			action(long ch)
{
	if (ch == SPACE)
		choose();
	else if (ch == BSPACE || ch == DEL)
		remove();
}
