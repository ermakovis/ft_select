/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:24:48 by tcase             #+#    #+#             */
/*   Updated: 2019/09/14 21:25:03 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	s_exit(long ch)
{
	if (!g_msh->select->elem_list)
		cleanup(SUCCESS, NULL);
	if (!(ch == RETURN || ch == ESC))
		return ;
	if (ch == ESC && g_msh->select->search_line[0])
		ft_bzero(g_msh->select->search_line, PATH_MAX);
	else if (ch == RETURN)
	{
		set_terminal_canon();
		print_selected();
		cleanup(SUCCESS, NULL);
	}
	else if (ch == ESC)
		cleanup(SUCCESS, NULL);
}

void	get_char(long *ch)
{
	*ch = 0;
	read(STDIN_FILENO, ch, sizeof(long));
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
		search(ch);
		s_exit(ch);
	}
}
