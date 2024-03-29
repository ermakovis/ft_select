/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:44:36 by tcase             #+#    #+#             */
/*   Updated: 2019/09/14 22:46:29 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include "ft_printf.h"
# include <stdbool.h>
# include <limits.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>
# include <term.h>
# include <signal.h>

# define SELECT_BUFF	260000
# define LEFT			4479771
# define RIGHT			4414235
# define UP				4283163
# define DOWN			4348699
# define RETURN			10
# define SPACE			32
# define BSPACE 		127
# define ESC			27
# define DEL 			2117294875

# define UNDERLINE		"\033[4m"
# define REVERSE		"\033[7m"
# define RESET			"\033[0m"
# define COL_DIR    	"\x1b[34m"
# define COL_CHR		"\x1b[43m\x1b[34m"
# define COL_BLK		"\x1b[46m\x1b[34m"
# define COL_EXE	    "\x1b[31m"
# define COL_FIF	    "\x1b[33m"
# define COL_LNK	    "\x1b[35m"

# define SELECT_OUTPUT	2

# define SUCCESS		0
# define FAILURE		-1

typedef struct winsize	t_wsize;
typedef struct termios	t_term;
typedef struct stat		t_stat;
typedef struct dirent	t_dir;

typedef struct			s_elem
{
	char				*line;
	bool				selected;
	bool				current;
}						t_elem;

typedef struct			s_size
{
	size_t				term_width;
	size_t				term_height;
	size_t				term_capacity;
	size_t				elem_maxlen;
	size_t				elem_count;
	size_t				column_count;
}						t_size;

typedef struct			s_select
{
	t_size				*size;
	t_list				*elem_list;
	char				search_line[PATH_MAX];
}						t_select;

typedef struct			s_cmd
{
	char				*area;
	char				*start;
	char				*clear_all;
	char				*clear_line;
	char				*clear_rest;
	char				*cur_start;
	char				*up;
	char				*left;
	char				*right;
	char				*del;
	char				*highlight_mode_on;
	char				*highlight_mode_off;
	char				*insert_mode_on;
	char				*insert_mode_off;
}						t_cmd;

typedef struct			s_msh
{
	t_term				*original_state;
	t_cmd				*cmd;
	t_select			*select;
}						t_msh;

t_msh					*g_msh;

void					cleanup(int exit_code, char *message);
void					init(void);
void					init_select(int ac, char **av);
void					init_select_args(int ac, char **av);
void					init_select_size(void);
void					move(long ch);
void					clear(void);
void					action(long ch);
void					search(long ch);
void					s_exit(long ch);
void					print(void);

/*
**	signal.c
*/
void					signal_main(void);

/*
**	terminal_mods.c
*/
void					set_terminal_raw(void);
void					set_terminal_canon(void);

/*
**	select_funcs.c
*/
void					add_elem(t_list **alist, char *line);
void					print_elem(t_list *list);
void					del_elem(void *content, size_t size);
int						cmp_elem_current(t_elem *elem, void *data_ref);
void					get_char(long *ch);
#endif
