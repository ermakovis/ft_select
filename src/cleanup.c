#include "ft_select.h"

void		cleanup_select(void)
{
	ft_memdel((void**)&g_msh->select->size);
	ft_lstdel(&(g_msh->select->elem_list), &del_elem);
	ft_memdel((void**)&g_msh->select);
}

void		cleanup(int exit_code, char *message)
{
	if (message)
		ft_dprintf(2, "%s\n", message);
	set_terminal_canon();
	cleanup_select();
	ft_memdel((void**)&g_msh->cmd->area);
	ft_memdel((void**)&g_msh->cmd);
	ft_memdel((void**)&g_msh->original_state);
	ft_memdel((void**)&g_msh);
	exit(exit_code);
}
