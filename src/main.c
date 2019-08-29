#include "ft_select.h"

void	set_terminal_raw(void)
{
	t_term	raw;

	if (!isatty(STDIN_FILENO))
		return ;
	if (tcgetattr(0, &raw) == -1)
		cleanup(-1, "Failed to save terminal original state");
	raw.c_lflag &= ~(ICANON | ECHO);
	if (tcsetattr(0, TCSANOW, &raw) == -1)
		cleanup(-1, "Failed to set terminal to raw mode");
}

void	set_terminal_canon(void)
{
	if (!isatty(STDIN_FILENO))
		return ;
	if (tcsetattr(0, TCSANOW, g_msh->original_state) == -1)
		cleanup(-1, "Failed to set terminal to canon mode");
}

void	handle_sigint(int sig)
{
	(void)sig;
	ft_printf("\n");
	set_terminal_canon();
	exit (0);
}

int		get_char(long *ch)
{
	*ch = 0;
	read(STDIN_FILENO, ch, sizeof(long));
	return (1);
}

int		main(int ac, char **av)
{
	long	ch;

	init();
	init_args(ac, av);
	set_terminal_raw();
	signal(SIGINT, handle_sigint);
	print();
	while (get_char(&ch))
	{
		if (ch == RETURN)
			break;
		move(ch);
		choose(ch);
		clear();
		print();
	}
	
	set_terminal_canon();
	return (0);
}	
