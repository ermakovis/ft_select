#include "ft_select.h"

void	clear(void)
{
	t_list		*list;
	int			output_hight;
	int			column_count;
	int			word_width;

	word_width = count_word_width(g_msh->select_list);
	column_count = count_columns(word_width);

	output_hight = ft_lstsize(g_msh->select_list) / column_count;
	list = g_msh->select_list;
	while(list->next)
		list = list->next;
	if (ft_strlen(((t_select*)list->content)->line) == word_width)
		output_hight++;
	while (output_hight--)
		ft_printf("%s", g_msh->cmd->up);
	ft_printf("%s", g_msh->cmd->start);	
}
