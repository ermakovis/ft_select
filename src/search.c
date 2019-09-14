/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:41:25 by tcase             #+#    #+#             */
/*   Updated: 2019/09/14 22:41:27 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		search_setcurrent(t_list *ref)
{
	t_list	*list;
	t_elem	*elem;

	list = g_msh->select->elem_list;
	while (list)
	{
		elem = list->content;
		if (list == ref)
			elem->current = 1;
		if (elem->current == 1 && list != ref)
			elem->current = 0;
		list = list->next;
	}
}

void		search_find(void)
{
	t_list	*list;
	t_elem	*elem;
	char	*search_line;

	list = g_msh->select->elem_list;
	search_line = g_msh->select->search_line;
	while (list)
	{
		elem = list->content;
		if (ft_strstr(elem->line, search_line))
		{
			search_setcurrent(list);
			return ;
		}
		list = list->next;
	}
}

void		search(long ch)
{
	size_t		len;
	char		*search_line;

	if (!ft_isprint((int)ch) || ch == ' ')
		return ;
	len = ft_strlen(g_msh->select->search_line);
	g_msh->select->search_line[len++] = (char)ch;
	if (len > 2)
		search_find();
}
