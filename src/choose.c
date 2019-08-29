#include "ft_select.h"

void		choose(long ch)
{
	t_list		*list;
	t_select	*select;

	if (ch != SPACE)
		return ;
	list = g_msh->select_list;
	while (list)
	{
		select = list->content;
		if (select->current == 1)
		{
			select->selected ^= 1;
			return ;
		}
		list = list->next;
	}
}
