#include "ft_select.h"

void		init_select(int ac, char **av)
{
	int		i;

	i = 0;
	while (av[++i] && i < ac)
		add_select(&g_msh->select_list, av[i]);
}
