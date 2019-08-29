#include "ft_select.h"

void		print_select(t_list *list)
{
	t_select	*select;

	select = list->content;
	ft_printf("| %s - %d - %d |\n", select->line, select->selected,\
		select->current);
}

void		del_select(void *content, int size)
{
	t_select	*select;

	select = content;
	select->selected = 0;
	select->current = 0;
	size = 0;
	ft_memdel((void**)&select);
}

static void		add_select(t_list **alist, char *line)
{
	t_select	*select;
	t_list		*new;

	if (!(select = (t_select*)ft_memalloc(sizeof(t_select))))
		cleanup(-1, "Malloc failed at add_select");
	select->line = line;
	if (!g_msh->select_list)
		select->current = 1;
	if (!(new = ft_lstnew(select, sizeof(t_select))))
		cleanup(-1, "Malloc failed at add_select");
	ft_lstadd_last(&g_msh->select_list, new);
}

void		init_args(int ac, char **av)
{
	int		i;

	i = 0;
	while (av[++i] && i < ac)
		add_select(&g_msh->select_list, av[i]);
}
