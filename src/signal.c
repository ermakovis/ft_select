/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:43:13 by tcase             #+#    #+#             */
/*   Updated: 2019/09/15 10:40:20 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	signal_quit(int sig)
{
	(void)sig;
	ft_printf("\n");
	set_terminal_canon();
	exit(0);
}

void	signal_cont(int sig)
{
	(void)sig;
	signal_main();
	set_terminal_raw();
	init_select_size();
	print();
}

void	signal_winch(int sig)
{
	(void)sig;
	set_terminal_raw();
	init_select_size();
	print();
}

void	signal_stop(int sig)
{
	(void)sig;
	set_terminal_canon();
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGABRT, SIG_DFL);
	signal(SIGSTOP, SIG_DFL);
	signal(SIGKILL, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGWINCH, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

void	signal_main(void)
{
	signal(SIGINT, signal_quit);
	signal(SIGQUIT, signal_quit);
	signal(SIGABRT, signal_quit);
	signal(SIGSTOP, signal_quit);
	signal(SIGKILL, signal_quit);
	signal(SIGTSTP, signal_stop);
	signal(SIGCONT, signal_cont);
	signal(SIGWINCH, signal_winch);
}
