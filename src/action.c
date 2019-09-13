#include "ft_select.h"

static void		remove(void)
{
	t_list		*list;
	t_elem		*elem;

	list = g_msh->select->elem_list;
	while (list)
	{
		elem = list->content;
		if (elem->current == 1)
		{
			ft_lst_remove(&g_msh->select->elem_list, &list, &del_elem);
			if (list->next)
				(((t_elem*)list->next->content)->current = 1);
			else
				(((t_elem*)g_msh->select->elem_list->content)->current = 1);
			return ;
		}
		list = list->next;
	}
}

static void		choose(void)
{
	t_list		*list;
	t_elem	*elem;

	list = g_msh->select->elem_list;
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

void		action(long ch)
{
	if (ch == SPACE)
		choose();
	else if (ch == BSPACE)
		remove();
}
