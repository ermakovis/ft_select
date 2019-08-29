#include "ft_select.h"

void	clear(void)
{
	int		output_hight;

	output_hight = ft_lstsize(g_msh->select_list);
	while (output_hight--)
		ft_printf("%s", g_msh->cmd->up);
	ft_printf("%s", g_msh->cmd->clear_rest);	
}
