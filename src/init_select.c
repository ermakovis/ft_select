#include "ft_select.h"

void		init_select_args(int ac, char **av)
{
	int		i;

	i = 0;
	while (av[++i] && i < ac)
		add_elem(&g_msh->select->elem_list, av[i]);
}

void		init_select_size(void)
{
	t_wsize		wsize;
	t_size		*size;
	t_list		*list;
	size_t		curlen;

	list = g_msh->select->elem_list;
	ioctl(0, TIOCGWINSZ, &wsize);
	size = g_msh->select->size;
	size->term_width = wsize.ws_col;
	size->term_height = wsize.ws_row;
	while (list)
	{
		curlen = ft_strlen(((t_elem*)list->content)->line);
		if (size->elem_maxlen < curlen)
			size->elem_maxlen = curlen;
		size->elem_count++;
		list = list->next;
	}
	size->column_count = wsize.ws_col / (size->elem_maxlen + 1);
}

void		init_select(int ac, char **av)
{

	if (!(g_msh->select = (t_select*)ft_memalloc(sizeof(t_select))))
		cleanup(-1, "Malloc failed at init_select");
	if (!(g_msh->select->size = (t_size*)ft_memalloc(sizeof(t_size))))
		cleanup(-1, "Malloc failed at init_select");
	init_select_args(ac, av);
	init_select_size();
}
