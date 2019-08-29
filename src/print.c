#include "ft_select.h"

void	print(void)
{
	t_list		*list;
	t_select	*select;

	list = g_msh->select_list;
	while (list)
	{
		select = list->content;
		if (select->selected == 1)
			ft_printf("%s", REVERSE);
		if (select->current == 1)
			ft_printf("%s", UNDERLINE);
		ft_printf("%s\n", select->line);
		ft_printf("%s", RESET);
		list = list->next;
	}

}
