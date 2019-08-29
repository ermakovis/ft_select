#include "ft_select.h"

static void		init_cmd_fill(t_cmd *cmd)
{
	cmd->start = tgetstr("cr", &cmd->area);
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

static void		init_cmd(void)
{
	t_cmd	*cmd;
	char	*term_name;
	char	buffer[SELECT_BUFF];

	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		cleanup(-1, "Failed to malloc for command structure");
	if (tgetent(buffer, getenv("TERM")) < 0)
		cleanup(-1, "Failed to get terminfo at init_term");
	if (!(cmd->area = ft_strnew(SELECT_BUFF)))
		cleanup(-1, "Malloc failed at init_term_command");
	ft_bzero(cmd, sizeof(t_cmd));
	init_cmd_fill(cmd);
	g_msh->cmd = cmd;
}

static void		init_msh(void)
{
	t_msh	*new_msh;

	if (!(new_msh = (t_msh*)malloc(sizeof(t_msh))))
		cleanup(-1, "Failed to malloc for main structure");
	ft_bzero(new_msh, sizeof(t_msh));
	g_msh = new_msh;
}

static void		init_orig_state(void)
{
	t_term	*orig;

	if (!(orig = (t_term*)malloc(sizeof(t_term))))
		cleanup(-1, "Failed to malloc for terminal state structure");
	if (tcgetattr(0, orig) == -1)
		cleanup(-1, "Failed to save terminal original state");
	g_msh->original_state = orig;
}

void			init(void)
{
	init_msh();
	init_cmd();
	init_orig_state();
}
