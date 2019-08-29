#ifndef FT_SELECT_H
# define FT_SELECT_H

#include "libft.h"
#include "ft_printf.h"
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
# define BSPACE 		127
# define RETURN			10
# define SPACE			32	

# define UNDERLINE		"\033[4m"
# define REVERSE		"\033[7m"
# define RESET			"\033[0m"

typedef struct winsize	t_wsize;
typedef struct termios	t_term;
typedef struct stat		t_stat;
typedef struct dirent	t_dir;

typedef struct			s_select
{
	char				*line;
	int					selected;
	int					current;
}						t_select;

typedef struct			s_cmd
{
	char				*area;
	char				*start;
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
	t_list				*select_list;
}						t_msh;

t_msh					*g_msh;
/*
**	cleanup.c
*/
void		cleanup(int exit_code, char *message);

/*
**	init.c
*/
void		init(void);

/*
** init_args.c.
** static void add_select(t_list **alist, char *line)
*/
void		init_args(int ac, char **av);
void		print_select(t_list *list);
void		del_select(void *content, int size);

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
**	choose.c
*/
void		choose(long ch);

/*
**	print.c
*/
void		print(void);
#endif
