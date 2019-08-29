#include "ft_select.h"

void		cleanup(int exit_code, char *message)
{
	if (message)
		ft_dprintf(2, "%s\n", message);
	if (exit_code != 1)
		exit(exit_code);
}
