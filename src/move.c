#include "ft_select.h"

void	move_left(void)
{
	t_list		*list;
	t_list		*prev;
	t_select	*select;

	prev = g_msh->select_list;
	list = prev->next;
	while (list)
	{
		select = list->content;
		if (select->current == 1)
		{
			select->current = 0;
			((t_select*)prev->content)->current = 1; 
			return ;
		}
		prev = list;
		list = list->next;
	}
	((t_select*)g_msh->select_list->content)->current = 0; 
	((t_select*)prev->content)->current = 1; 
}

void	move_right(void)
{
	t_list		*list;
	t_select	*select;

	list = g_msh->select_list;
	while (list)
	{
		select = list->content;
		if (select->current == 1)
		{
			select->current = 0;
			if (list->next)
				((t_select*)list->next->content)->current = 1;
			else
				((t_select*)g_msh->select_list->content)->current = 1; 
			return ;
		}
		list = list->next;
	}
}


void	move(long ch)
{
	if (!(ch == LEFT || ch == RIGHT || ch == UP || ch == DOWN))
		return ;
	if (ch == LEFT)
		move_left();
	else if (ch == RIGHT)
		move_right();
}

