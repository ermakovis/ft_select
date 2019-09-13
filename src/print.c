#include "ft_select.h"

void	print(void)
{
	t_list		*list;
	t_elem		*elem;
	t_size		*size;
	int			i;

	i = 0;
	ft_putstr(g_msh->cmd->clear_all);
	size = g_msh->select->size;
	list = g_msh->select->elem_list;
	while (list)
	{
		i++;
		elem = list->content;
		if (elem->selected == 1)
			ft_printf("%s", REVERSE);
		if (elem->current == 1)
			ft_printf("%s", UNDERLINE);
		ft_printf(" %-*s", size->elem_maxlen, elem->line);
		ft_printf("%s", RESET);
		list = list->next;
		if (i == size->column_count)
		{
			ft_printf("\n");
			i = 0;
		}
	}
}
