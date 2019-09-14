/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:26:15 by tcase             #+#    #+#             */
/*   Updated: 2019/09/14 22:34:17 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_list	*print_getlist(t_list *list, t_size *size)
{
	t_list	*ret;
	size_t	cur_pos;

	cur_pos = 0;
	if (size->term_capacity >= size->elem_count)
		return (list);
	ret = list;
	while (ret)
	{
		if (((t_elem*)ret->content)->current == true)
			break ;
		cur_pos++;
		ret = ret->next;
	}
	if (size->elem_count - cur_pos >= size->term_capacity)
		return (ret);
	cur_pos = size->elem_count - size->term_capacity;
	ret = list;
	while (cur_pos--)
		ret = ret->next;
	return (ret);
}

static void		print_line_color(char *line)
{
	int		item_type;

	if ((item_type = ft_item_type(line)) > 0)
	{
		if (item_type == 2)
			ft_dprintf(SELECT_OUTPUT, COL_DIR);
		else if (item_type == 3)
			ft_dprintf(SELECT_OUTPUT, COL_LNK);
		else if (item_type == 4)
			ft_dprintf(SELECT_OUTPUT, COL_FIF);
		else if (item_type == 5)
			ft_dprintf(SELECT_OUTPUT, COL_CHR);
		else if (item_type == 6)
			ft_dprintf(SELECT_OUTPUT, COL_BLK);
		else if (item_type == 7)
			ft_dprintf(SELECT_OUTPUT, COL_EXE);
	}
}

static void		print_line(t_elem *elem)
{
	char	*line;
	size_t	term_width;
	size_t	line_maxlen;

	line = elem->line;
	term_width = g_msh->select->size->term_width;
	line_maxlen = g_msh->select->size->elem_maxlen;
	if (elem->selected == true)
		ft_dprintf(SELECT_OUTPUT, REVERSE);
	if (elem->current == true)
		ft_dprintf(SELECT_OUTPUT, UNDERLINE);
	print_line_color(line);
	if (line_maxlen < term_width)
		ft_dprintf(SELECT_OUTPUT, " %-*s", line_maxlen, line);
	else
	{
		ft_dprintf(SELECT_OUTPUT, "%.*s", term_width - 3, line);
		if (term_width - 3 <= ft_strlen(line))
			ft_dprintf(SELECT_OUTPUT, "...");
	}
	ft_dprintf(SELECT_OUTPUT, RESET);
}

static void		print_search(void)
{
	char	*line;
	size_t	term_width;
	size_t	line_maxlen;

	line = g_msh->select->search_line;
	term_width = g_msh->select->size->term_width;
	line_maxlen = ft_strlen(g_msh->select->search_line);
	if (line_maxlen < term_width)
		ft_dprintf(SELECT_OUTPUT, " %-*s", line_maxlen, line);
	else
	{
		ft_dprintf(SELECT_OUTPUT, "%.*s", term_width - 3, line);
		if (term_width - 3 <= ft_strlen(line))
			ft_dprintf(SELECT_OUTPUT, "...");
	}
}

void			print(void)
{
	t_list		*list;
	t_size		*size;
	size_t		capacity;
	int			i;

	i = 0;
	ft_dprintf(2, "%s", g_msh->cmd->clear_all);
	size = g_msh->select->size;
	capacity = size->term_capacity;
	list = print_getlist(g_msh->select->elem_list, size);
	while (list && capacity--)
	{
		i++;
		print_line(list->content);
		list = list->next;
		if (i == size->column_count && ft_dprintf(SELECT_OUTPUT, "\n"))
			i = 0;
	}
	if (i)
		ft_dprintf(SELECT_OUTPUT, "\n");
	if (g_msh->select->search_line[0])
		print_search();
}
