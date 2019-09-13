#include "ft_select.h"

void	print_selected(void)
{
	t_list	*list;
	t_elem	*elem;
	bool	first;

	first = true;
	list = g_msh->select->elem_list;
	while (list)
	{
		elem = list->content;
		if (elem->selected == true)
		{
			if (first)
				first = false;
			else 
				ft_printf(" ");
			ft_printf("%s", elem->line);
		}
		list = list->next;
	}
}

void	get_char(long *ch)
{
	*ch = 0;
	read(STDIN_FILENO, ch, sizeof(long));
	if (*ch == RETURN)
	{
		set_terminal_canon();
		print_selected();
		cleanup(SUCCESS, NULL);
	}
	if (*ch == ESC)
		cleanup(SUCCESS, NULL);
}

int		main(int ac, char **av)
{
	long	ch;

	if (ac == 1)
		return (SUCCESS);
	init();
	init_select(ac, av);
	set_terminal_raw();
	signal_main();
	while (true)
	{
		print();
		get_char(&ch);
		move(ch);
		action(ch);
	}
}	
