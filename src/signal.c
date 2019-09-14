/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:43:13 by tcase             #+#    #+#             */
/*   Updated: 2019/09/14 22:43:14 by tcase            ###   ########.fr       */
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
	signal(SIGTSTP, SIG_DFL);
	signal(SIGINT, SIG_DFL);
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
