#include "ft_select.h"

void		choose(long ch)
{
	t_list		*list;
	t_elem	*elem;

	if (ch != SPACE)
		return ;
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
