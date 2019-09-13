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
	if (tcsetattr(STDERR_FILENO, TCSANOW, g_msh->original_state) == -1)
		cleanup(-1, "Failed to set terminal to canon mode");
}

void	get_char(long *ch)
{
	*ch = 0;
	read(STDIN_FILENO, ch, sizeof(long));
	if (*ch == RETURN)
		cleanup(0, "SUCCESS");
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
		choose(ch);
	}
	set_terminal_canon();
	return (SUCCESS);
}	
