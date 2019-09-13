#include "ft_select.h"

void	set_terminal_raw(void)
{
	t_term	raw;

	if (tcgetattr(STDERR_FILENO, &raw) == -1)
		cleanup(-1, "Failed to save terminal original state");
	raw.c_lflag &= ~(ICANON | ECHO);
	if (tcsetattr(0, TCSANOW, &raw) == -1)
		cleanup(-1, "Failed to set terminal to raw mode");
	ft_dprintf(2, "%s", (tgetstr("ti", NULL)));
	ft_dprintf(2, "%s", (tgetstr("vi", NULL)));
}

void	set_terminal_canon(void)
{
	ft_dprintf(2, "%s", (tgetstr("te", NULL)));
	ft_dprintf(2, "%s", (tgetstr("ve", NULL)));
	if (tcsetattr(STDERR_FILENO, TCSANOW, g_msh->original_state) == -1)
		cleanup(-1, "Failed to set terminal to canon mode");
}
