#include "ft_select.h"

void	print_line(size_t line_maxlen, size_t term_width, char *line)
{
	int		item_type;

	if (line_maxlen < term_width)
		ft_dprintf(SELECT_OUTPUT, " %-*s", line_maxlen, line);
	else
	{
		ft_dprintf(SELECT_OUTPUT, "%.*s", term_width - 3, line);
		if (term_width - 3 <= ft_strlen(line))
			ft_dprintf(SELECT_OUTPUT, "...");
	}
}

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
		print_line(size->elem_maxlen, size->term_width, elem->line);
		ft_dprintf(SELECT_OUTPUT, "%s", RESET);
		list = list->next;
		if (i == size->column_count && ft_dprintf(SELECT_OUTPUT, "\n"))
			i = 0;
	}
}
