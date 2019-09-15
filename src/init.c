/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:23:59 by tcase             #+#    #+#             */
/*   Updated: 2019/09/15 11:24:09 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		init_cmd_fill(t_cmd *cmd)
{
	cmd->start = tgetstr("cr", &cmd->area);
	cmd->clear_all = tgetstr("cl", &cmd->area);
	cmd->clear_line = tgetstr("ce", &cmd->area);
	cmd->clear_rest = tgetstr("cd", &cmd->area);
	cmd->cur_start = tgetstr("cr", &cmd->area);
	cmd->up = tgetstr("up", &cmd->area);
	cmd->left = tgetstr("le", &cmd->area);
	cmd->right = tgetstr("nd", &cmd->area);
	cmd->del = tgetstr("dc", &cmd->area);
	cmd->highlight_mode_on = tgetstr("so", &cmd->area);
	cmd->highlight_mode_off = tgetstr("se", &cmd->area);
	cmd->insert_mode_on = tgetstr("im", &cmd->area);
	cmd->insert_mode_off = tgetstr("ei", &cmd->area);
}

static t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;
	char	*term_name;
	char	buffer[SELECT_BUFF];
	int		res;

	if (!(term_name = getenv("TERM")))
	{
		ft_dprintf(2, "Failed to get term name\n");
		exit(FAILURE);
	}
	if (tgetent(buffer, term_name) < 1)
	{
		ft_dprintf(2, "Failed to get info from terminfo database\n");
		exit(FAILURE);
	}
	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		cleanup(-1, "Failed to malloc for command structure");
	ft_bzero(cmd, sizeof(t_cmd));
	init_cmd_fill(cmd);
	return (cmd);
}

static void		init_msh(void)
{
	t_msh	*new_msh;

	if (!(new_msh = (t_msh*)malloc(sizeof(t_msh))))
		cleanup(-1, "Failed to malloc for main structure");
	ft_bzero(new_msh, sizeof(t_msh));
	g_msh = new_msh;
}

static t_term	*init_orig_state(void)
{
	t_term	*orig;

	if (!(orig = (t_term*)malloc(sizeof(t_term))))
		exit(FAILURE);
	if (tcgetattr(STDERR_FILENO, orig) == -1)
		exit(FAILURE);
	return (orig);
}

void			init(void)
{
	t_cmd		*cmd;
	t_term		*term;

	cmd = init_cmd();
	term = init_orig_state();
	init_msh();
	g_msh->cmd = cmd;
	g_msh->original_state = term;
}
