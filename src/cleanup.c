#include "ft_select.h"

void		cleanup(int exit_code, char *message)
{
	if (message)
		ft_dprintf(2, "%s\n", message);
	set_terminal_canon();
	exit(exit_code);
}
