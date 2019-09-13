#include "ft_select.h"

static void	move_left(void)
{
	t_list		*list;
	t_list		*prev;
	t_elem		*elem;	

	prev = g_msh->select->elem_list;
	list = prev->next;
	while (list)
	{
		elem = list->content;
		if (elem->current == 1)
		{
			elem->current = 0;
			((t_elem*)prev->content)->current = 1; 
			return ;
		}
		prev = list;
		list = list->next;
	}
	((t_elem*)g_msh->select->elem_list->content)->current = 0; 
	((t_elem*)prev->content)->current = 1; 
}

static void	move_right(void)
{
	t_list		*list;
	t_elem		*elem;

	list = g_msh->select->elem_list;
	while (list)
	{
		elem = list->content;
		if (elem->current == 1)
		{
			elem->current = 0;
			if (list->next)
				((t_elem*)list->next->content)->current = 1;
			else
				((t_elem*)g_msh->select->elem_list->content)->current = 1;
			return ;
		}
		list = list->next;
	}
}

static void	move_up(void)
{
	size_t	moves_count;

	moves_count = g_msh->select->size->column_count;
	while(moves_count--)
		move_left();
}

static void	move_down(void)
{
	size_t	moves_count;

	moves_count = g_msh->select->size->column_count;
	while(moves_count--)
		move_right();
}

void	move(long ch)
{
	if (!(ch == LEFT || ch == RIGHT || ch == UP || ch == DOWN))
		return ;
	if (ch == LEFT)
		move_left();
	else if (ch == RIGHT)
		move_right();
	else if (ch == UP)
		move_up();
	else if (ch == DOWN)
		move_down();
}

