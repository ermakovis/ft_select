#include "ft_select.h"

void	print(void)
{
	t_list		*list;
	t_elem		*elem;
	t_size		*size;
	int			i;

	i = 0;
	ft_dprintf(2, "%s", g_msh->cmd->clear_all);
	size = g_msh->select->size;
	list = g_msh->select->elem_list;
	while (list)
	{
		i++;
		elem = list->content;
		if (elem->selected == 1)
			ft_dprintf(SELECT_OUTPUT, "%s", REVERSE);
		if (elem->current == 1)
			ft_dprintf(SELECT_OUTPUT, "%s", UNDERLINE);
		ft_dprintf(SELECT_OUTPUT, " %-*s", size->elem_maxlen, elem->line);
		ft_dprintf(SELECT_OUTPUT, "%s", RESET);
		list = list->next;
		if (i == size->column_count && ft_dprintf(SELECT_OUTPUT, "\n"))
			i = 0;
	}
}
