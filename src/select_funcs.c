#include "ft_select.h"

int			cmp_elem_current(t_elem *elem, void *data_ref)
{
	int		*ref;

	ref = data_ref;
	if (elem->current == *ref)
		return (0);
	return (1);

}

void		print_elem(t_list *list)
{
	t_elem	*elem;

	elem = list->content;
	ft_dprintf(SELECT_OUTPUT, "| %s - %d - %d |\n", elem->line, elem->selected,\
		elem->current);
}

void		del_elem(void *content, int size)
{
	t_elem	*elem;

	elem = content;
	elem->selected = 0;
	elem->current = 0;
	size = 0;
	ft_memdel((void**)&elem);
}

void		add_elem(t_list **alist, char *line)
{
	t_elem	*elem;
	t_list	*new;

	if (!(elem = (t_elem*)ft_memalloc(sizeof(t_elem))))
		cleanup(-1, "Malloc failed at add_elem");
	elem->line = line;
	if (!g_msh->select->elem_list)
		elem->current = 1;
	if (!(new = ft_lstnew(elem, sizeof(t_elem))))
		cleanup(-1, "Malloc failed at add_elem");
	ft_lstadd_last(&g_msh->select->elem_list, new);
}
