#include "ft_select.h"

/*
**	width++ to ensure that at least 1 space will be between words
*/
int		count_word_width(t_list *list)
{
	int			width;
	int			cur_width;
	t_select	*select;

	width = 0;
	while (list)
	{
		select = list->content;
		if (((cur_width = ft_strlen(select->line)) > width))
			width = cur_width;
		list = list->next;
	}
	return (width);
}

int		count_columns(int word_width)
{
	int			term_width;
	int			col_count;
	t_wsize		wsize;

	ioctl(0, TIOCGWINSZ, &wsize);
	term_width = wsize.ws_col;
	col_count = term_width / (word_width + 1);
	return (col_count);
}

void	print(void)
{
	t_list		*list;
	t_select	*select;
	int			column_count;
	int			word_width;
	int			i;

	i = 0;
	ft_putstr(g_msh->cmd->clear_all);
	list = g_msh->select_list;
	word_width = count_word_width(list);
	column_count = count_columns(word_width);
	while (list)
	{
		i++;
		select = list->content;
		if (select->selected == 1)
			ft_printf("%s", REVERSE);
		if (select->current == 1)
			ft_printf("%s", UNDERLINE);
		ft_printf(" %-*s", word_width, select->line);
		ft_printf("%s", RESET);
		list = list->next;
		if (i == column_count)
		{
			ft_printf("\n");
			i = 0;
		}
	}
}
