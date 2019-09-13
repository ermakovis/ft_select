#ifndef FT_SELECT_H
# define FT_SELECT_H

#include "libft.h"
#include "ft_printf.h"
#include <stdbool.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <term.h>
#include <signal.h>

# define SELECT_BUFF	260000
# define LEFT			4479771
# define RIGHT			4414235
# define UP				4283163
# define DOWN			4348699
# define RETURN			10
# define SPACE			32	
# define BSPACE 		127
# define DEL			27
# define ESC 			2117294875

# define UNDERLINE		"\033[4m"
# define REVERSE		"\033[7m"
# define RESET			"\033[0m"

# define SUCCESS		0
# define FAILURE		-1
# define SELECT_OUTPUT	2

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
	size_t				elem_maxlen;
	size_t				elem_count;
	size_t				column_count;
}						t_size;

typedef struct			s_select
{
	t_size				*size;
	t_list				*elem_list;
	t_list				*selected_list;
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

/*
**	main.c
*/

/*
**	cleanup.c
*/
void		cleanup(int exit_code, char *message);

/*
**	init.c
*/
void		init(void);

/*
** init_select.c.
*/
void		init_select(int ac, char **av);
void		init_select_args(int ac, char **av);
void		init_select_size(void);

/*
** move.c
*/
void		move_left(void);
void		move_right(void);
void		move_up(void);
void		move_down(void);
void		move(long ch);

/*
**	clear.c
*/
void		clear(void);

/*
**	action.c
*/
void		action(long ch);

/*
**	print.c
*/
void		print(void);
int			count_columns(int word_width);
int			count_word_width(t_list *list);

/*
**	signal.c
*/
void		signal_main(void);

/*
**	terminal_mods.c
*/
void		set_terminal_raw(void);
void		set_terminal_canon(void);

/*
**	select_funcs.c
*/
void		add_elem(t_list **alist, char *line);
void		print_elem(t_list *list);
void		del_elem(void *content, int size);
int			cmp_elem_current(t_elem *elem, void *data_ref);


#endif
