#include "ft_select.h"

void	print_line(size_t line_maxlen, size_t term_width, char *line)
{
	int		item_type;

	if ((item_type = ft_item_type(line)) > 0)
	{
		if (item_type == 2)
			ft_dprintf(SELECT_OUTPUT, COL_DIR);
		else if (item_type == 3)
			ft_dprintf(SELECT_OUTPUT, COL_LNK);
		else if (item_type == 4)
			ft_dprintf(SELECT_OUTPUT, COL_FIF);
		else if (item_type == 5)
			ft_dprintf(SELECT_OUTPUT, COL_CHR);
		else if (item_type == 6)
			ft_dprintf(SELECT_OUTPUT, COL_BLK);
		else if (item_type == 7)
			ft_dprintf(SELECT_OUTPUT, COL_EXE);
	}
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
			ft_dprintf(SELECT_OUTPUT, REVERSE);
		if (elem->current == 1)
			ft_dprintf(SELECT_OUTPUT, UNDERLINE);
		print_line(size->elem_maxlen, size->term_width, elem->line);
		ft_dprintf(SELECT_OUTPUT, RESET);
		list = list->next;
		if (i == size->column_count && ft_dprintf(SELECT_OUTPUT, "\n"))
			i = 0;
	}
}
